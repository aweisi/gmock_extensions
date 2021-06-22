/* gmock_extension
* Copyright (C) 2021  aweisi
* 
* This file is part of gmock_extension.
* 
* gmock_extension is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
* 
* gmock_extension is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with gmock_extension.  If not, see <http://www.gnu.org/licenses/>.
*/

// IF you use SCOPED_TRACE MACRO please disable the MemoryLeakDetector
// TEST(test1, without_memory_check)
// {
//  this->RecordProperty( "MemoryLeakDetector", "ON" );
// }
#ifndef MEMEORY_LEAK_DETECTOR_HH_INLCUDE_GUARD
#define MEMEORY_LEAK_DETECTOR_HH_INLCUDE_GUARD

#if defined(_MSC_VER) && defined(_DEBUG)
# include <gtest/gtest.h>
# include <crtdbg.h>
# include <string>
# include <cstring>    // tolower
# include <algorithm>  // std::equal
# define MEMEORY_LEAK_DETECTOR_HH
#endif

namespace TestingExtension
{
#ifdef MEMEORY_LEAK_DETECTOR_HH
    static const std::string ml( "MemoryLeakDetector" );
    class MemoryLeakDetector : public ::testing::EmptyTestEventListener
    {
        static bool prd( std::string::value_type i, std::string::value_type j )
        {
            return ( tolower( i ) == tolower( j ) );
        }
    public:
        virtual void OnTestStart( ::testing::TestInfo const& )
        {
            _CrtMemCheckpoint( &memState_ );
        }
        virtual void OnTestEnd( ::testing::TestInfo const& info )
        {
            bool memoryLeakCheckEnabled = false;
            for( int i = 0; i < info.result( )->test_property_count( ); i++ )
            {
                std::string key( info.result( )->GetTestProperty( i ).key( ) );
                if( ml.size( ) == key.size( ) && std::equal( key.begin( ), key.end( ), ml.begin( ), prd ) )
                {
                    memoryLeakCheckEnabled = true;
                    break;
                }
            }
            if( memoryLeakCheckEnabled && info.result( )->Passed( ) )
            {
                _CrtMemState stateNow, stateDiff;
                _CrtMemCheckpoint( &stateNow );
                if( _CrtMemDifference( &stateDiff, &memState_, &stateNow ) )
                {
                    FAIL( ) << "Memory leak of " << stateDiff.lSizes[ 1 ] << " byte(s) detected.\n";
                }
            }
        }
    private:
        _CrtMemState memState_;
    };
#endif

    class MemoryLeakDetectorGuard {
    public:
        MemoryLeakDetectorGuard( );
        ~MemoryLeakDetectorGuard( );
    private:
#ifdef MEMEORY_LEAK_DETECTOR_HH
        _CrtMemState memState_;
        void chk( ) const;
#endif
    };
}
#endif
