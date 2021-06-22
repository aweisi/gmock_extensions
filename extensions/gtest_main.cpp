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
#include <stdio.h>
#include "memory_leak_detector.hpp"
#include "gmock_extensions.hpp"
#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <algorithm>

GTEST_API_ int main(int argc, char** argv) {
  std::cout << "Running main from " << __FILE__ << "\n";
  // no need for calling testing::InitGoogleTest() separately.
  ::testing::InitGoogleMock(&argc, argv);
# ifdef MEMEORY_LEAK_DETECTOR_HH
  ::testing::UnitTest::GetInstance( )->
   listeners( ).Append( new TestingExtension::MemoryLeakDetector( ) );
# endif
  ::testing::UnitTest::GetInstance( )->
  listeners( ).Append( new TestingExtension::MockVerifyAndClearExpectation( ) );
  return RUN_ALL_TESTS();
}

namespace TestingExtension { 
#ifdef MEMEORY_LEAK_DETECTOR_HH
MemoryLeakDetectorGuard::MemoryLeakDetectorGuard( ) : memState_( ) {
  _CrtMemCheckpoint( &memState_ );
}
MemoryLeakDetectorGuard::~MemoryLeakDetectorGuard( ) { this->chk( ); }
void MemoryLeakDetectorGuard::chk( ) const {
  _CrtMemState stateNow, stateDiff;
  _CrtMemCheckpoint( &stateNow );
  if( _CrtMemDifference( &stateDiff, &memState_, &stateNow ) ) {
    FAIL( ) << "Memory leak of " << stateDiff.lSizes[ 1 ] << " byte(s) detected.\n";
  }
}
#else
MemoryLeakDetectorGuard::MemoryLeakDetectorGuard( ) { }
MemoryLeakDetectorGuard::~MemoryLeakDetectorGuard( ) { }
#endif

   int IMockBase::genId( ) { static int cnt = 0; return cnt++; }
   IMockBase::IMockBase( ) : id( genId( ) ) { }
   IMockBase::~IMockBase( ) { }
   int IMockBase::GetId( ) { return this->id; }

  typedef std::vector<IMockBase *> MyMockList;
  static MyMockList * getLIstOfMocks( );

  void MockVerifyAndClearExpectation::OnTestStart( ::testing::TestInfo const& )
  {
    for( MyMockList::iterator i = getLIstOfMocks( )->begin( ); i != getLIstOfMocks( )->end( ); ++i )
    {
      (*i)->Reset( );
    }
  }

  void MockVerifyAndClearExpectation::OnTestEnd( ::testing::TestInfo const&  )
  {
    for( MyMockList::iterator i = getLIstOfMocks( )->begin( ); i != getLIstOfMocks( )->end( ); ++i )
    {
      ::testing::Mock::VerifyAndClearExpectations( *i );
    }
  }

  void MockVerifyAndClearExpectation::OnTestProgramEnd( ::testing::UnitTest const&  )
  {
    for( MyMockList::iterator i = getLIstOfMocks( )->begin( ); i != getLIstOfMocks( )->end( ); ++i )
    { //::testing::Mock::AllowLeak( *i );
      delete *i;
    }
    getLIstOfMocks( )->clear();
  }
  void MockVerifyAndClearExpectation::add( IMockBase * obj )
  {
    getLIstOfMocks( )->push_back( obj );
  }

  namespace { 
      struct Pred { 
        IMockBase * obj;
        explicit Pred( IMockBase * o ) : obj(o) { }
        bool operator()( IMockBase * t ) { return obj->GetId( ) == t->GetId( ); }
      };
  }

  void MockVerifyAndClearExpectation::remove( IMockBase * obj )
  {
      MyMockList::iterator t =  std::find_if( getLIstOfMocks( )->begin( ), getLIstOfMocks( )->end( ), Pred(obj) );
      if( t != getLIstOfMocks( )->end( ) )
        getLIstOfMocks( )->erase( t );
  }
  static MyMockList * getLIstOfMocks( )
  {
    static MyMockList mock_list;
    return &mock_list;
  }
}
