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
#include "gmock_extensions.hpp"

#include <gtest/gtest-spi.h> //only for testing extension or gtest itself don't use in your code

// file_module_under_test.c
extern "C"
{
    void c_fct_MOCK_0 ( );
    void c_fct_MOCK_1 ( int );
    void c_fct_MOCK_2 ( int, int );
    void c_fct_MOCK_3 ( int, int, int );
    void c_fct_MOCK_4 ( int, int, int, int );
    void c_fct_MOCK_5 ( int, int, int, int, int );
    void c_fct_MOCK_6 ( int, int, int, int, int, int );
    void c_fct_MOCK_7 ( int, int, int, int, int, int, int );
    void c_fct_MOCK_8 ( int, int, int, int, int, int, int, int );
    void c_fct_MOCK_9 ( int, int, int, int, int, int, int, int, int );
    void c_fct_MOCK_10( int, int, int, int, int, int, int, int, int, int );

    void c_fct_MOCK_0_TEST  ( )                                                                                  { c_fct_MOCK_0 ( );                                                    }
    void c_fct_MOCK_1_TEST  ( int a0 )                                                                           { c_fct_MOCK_1  ( a0 )                                               ; }
    void c_fct_MOCK_2_TEST  ( int a0, int a1  )                                                                  { c_fct_MOCK_2  ( a0, a1  )                                          ; }
    void c_fct_MOCK_3_TEST  ( int a0, int a1 , int a2  )                                                         { c_fct_MOCK_3  ( a0, a1 ,  a2  )                                    ; }
    void c_fct_MOCK_4_TEST  ( int a0, int a1 , int a2 , int a3  )                                                { c_fct_MOCK_4  ( a0, a1 ,  a2 ,  a3  )                              ; }
    void c_fct_MOCK_5_TEST  ( int a0, int a1 , int a2 , int a3 , int a4  )                                       { c_fct_MOCK_5  ( a0, a1 ,  a2 ,  a3 ,  a4  )                        ; }
    void c_fct_MOCK_6_TEST  ( int a0, int a1 , int a2 , int a3 , int a4 , int a5 )                               { c_fct_MOCK_6  ( a0, a1 ,  a2 ,  a3 ,  a4 ,  a5 )                   ; }
    void c_fct_MOCK_7_TEST  ( int a0, int a1 , int a2 , int a3 , int a4 , int a5, int a6 )                       { c_fct_MOCK_7  ( a0, a1 ,  a2 ,  a3 ,  a4 ,  a5,  a6 )              ; }
    void c_fct_MOCK_8_TEST  ( int a0, int a1 , int a2 , int a3 , int a4 , int a5, int a6, int a7 )               { c_fct_MOCK_8  ( a0, a1 ,  a2 ,  a3 ,  a4 ,  a5,  a6,  a7 )         ; }
    void c_fct_MOCK_9_TEST  ( int a0, int a1 , int a2 , int a3 , int a4 , int a5, int a6, int a7, int a8 )       { c_fct_MOCK_9  ( a0, a1 ,  a2 ,  a3 ,  a4 ,  a5,  a6,  a7,  a8 )    ; }
    void c_fct_MOCK_10_TEST ( int a0, int a1 , int a2 , int a3 , int a4 , int a5, int a6, int a7, int a8, int a9){ c_fct_MOCK_10 ( a0, a1 ,  a2 ,  a3 ,  a4 ,  a5,  a6,  a7,  a8,  a9); }

    int c_fct_to_mock( );
    int c_fct_to_mock2( );
    int c_fct_to_mock3( int );
    void c_fct_to_mock4( );
    void c_fct_to_mock5( );
    void c_fct_to_mock6( );
    void c_fct_to_mock7( );

    int my1st( int i, int b )
    {
        std::cout << "my1st" << std::endl;
        int c = c_fct_to_mock( ) + i + b;
        std::cout << " c " << c << " , i " << i << " , b " << b << std::endl;
        return c;
    }
    int my2nd( int i, int b )
    {
        std::cout << "my2nd" << std::endl;
        int c = c_fct_to_mock( ) + i + b;
        std::cout << " c " << c << " , i " << i << " , b " << b << std::endl;
        c += c_fct_to_mock2( );
        return c;
    }
    int my3rd( int i, int b )
    {
        std::cout << "my3rd" << std::endl;
        int c = c_fct_to_mock3( i + b );
        std::cout << " c " << c << " , i " << i << " , b " << b << std::endl;
        return c;
    }
    void my4th( )
    {
        std::cout << "my4th" << std::endl;
        c_fct_to_mock4( );
    }
    void my5th( )
    {
        std::cout << "my5th" << std::endl;
        c_fct_to_mock5( );
    }
    void my6th( )
    {
        std::cout << "my6th" << std::endl;
        c_fct_to_mock6( );
    }
    void my7th( )
    {
        std::cout << "my6th" << std::endl;
        c_fct_to_mock7( );
    }
}

MOCK_FUNCTION(void, c_fct_MOCK_0, ());
MOCK_FUNCTION(void, c_fct_MOCK_1, (int));
MOCK_FUNCTION(void, c_fct_MOCK_2, (int, int));
MOCK_FUNCTION(void, c_fct_MOCK_3, (int, int, int));
MOCK_FUNCTION(void, c_fct_MOCK_4, (int, int, int, int));
MOCK_FUNCTION(void, c_fct_MOCK_5, (int, int, int, int, int));
MOCK_FUNCTION(void, c_fct_MOCK_6, (int, int, int, int, int, int));
MOCK_FUNCTION(void, c_fct_MOCK_7, (int, int, int, int, int, int, int));
MOCK_FUNCTION(void, c_fct_MOCK_8, (int, int, int, int, int, int, int, int));
MOCK_FUNCTION(void, c_fct_MOCK_9, (int, int, int, int, int, int, int, int, int));
MOCK_FUNCTION(void, c_fct_MOCK_10, (int, int, int, int, int, int, int, int, int, int ));

MOCK_FUNCTION(int , c_fct_to_mock,   ()                                                   );
MOCK_FUNCTION(int , c_fct_to_mock2,  ()                                                   );
MOCK_FUNCTION(int , c_fct_to_mock3,  (int)                                              );
MOCK_FUNCTION(void, c_fct_to_mock4,  ()                                                      );
MOCK_FUNCTION(void, c_fct_to_mock5,  ()                                                      );
MOCK_FUNCTION(void, c_fct_to_mock6,  ()                                                      );
MOCK_FUNCTION(void, c_fct_to_mock7,  ()                                                      );
MOCK_FUNCTION(void, c_fct_to_mock8,  (int, int)                                        );
MOCK_FUNCTION(void, c_fct_to_mock9,  (int, int, int)                                   );
MOCK_FUNCTION(void, c_fct_to_mock10, (int, int, int, int)                              );
MOCK_FUNCTION(void, c_fct_to_mock11, (int, int, int, int, int)                         );
MOCK_FUNCTION(void, c_fct_to_mock12, (int, int, int, int, int, int)                    );
MOCK_FUNCTION(void, c_fct_to_mock13, (int, int, int, int, int, int, int)               );
MOCK_FUNCTION(void, c_fct_to_mock14, (int, int, int, int, int, int, int, int)          );
MOCK_FUNCTION(void, c_fct_to_mock15, (int, int, int, int, int, int, int, int, int)     );
MOCK_FUNCTION(void, c_fct_to_mock16, (int, int, int, int, int, int, int, int, int, int));


TEST( C_FUNCTIONS, paramterForwarding )
{
    // 1st create the MOCK
    auto  & o0  = c_fct_MOCK_0_MOCK_TYPE::CreateStrict( );
    auto  & o1  = c_fct_MOCK_1_MOCK_TYPE::CreateStrict( );
    auto  & o2  = c_fct_MOCK_2_MOCK_TYPE::CreateStrict( );
    auto  & o3  = c_fct_MOCK_3_MOCK_TYPE::CreateStrict( );
    auto  & o4  = c_fct_MOCK_4_MOCK_TYPE::CreateStrict( );
    auto  & o5  = c_fct_MOCK_5_MOCK_TYPE::CreateStrict( );
    auto  & o6  = c_fct_MOCK_6_MOCK_TYPE::CreateStrict( );
    auto  & o7  = c_fct_MOCK_7_MOCK_TYPE::CreateStrict( );
    auto  & o8  = c_fct_MOCK_8_MOCK_TYPE::CreateStrict( );
    auto  & o9  = c_fct_MOCK_9_MOCK_TYPE::CreateStrict( );
    auto  & o10 = c_fct_MOCK_10_MOCK_TYPE::CreateStrict( );

    // 2nd USE the MOCKS
    EXPECT_CALL( o0,  c_fct_MOCK_0( ) );
    EXPECT_CALL( o1,  c_fct_MOCK_1( 1 ) );
    EXPECT_CALL( o2,  c_fct_MOCK_2( 1 , 2) );
    EXPECT_CALL( o3,  c_fct_MOCK_3( 1 , 2 , 3) );
    EXPECT_CALL( o4,  c_fct_MOCK_4( 1 , 2 , 3, 4) );
    EXPECT_CALL( o5,  c_fct_MOCK_5( 1 , 2 , 3, 4 , 5) );
    EXPECT_CALL( o6,  c_fct_MOCK_6( 1 , 2 , 3, 4 , 5 , 6) );
    EXPECT_CALL( o7,  c_fct_MOCK_7( 1 , 2 , 3, 4 , 5 , 6 , 7 ) );
    EXPECT_CALL( o8,  c_fct_MOCK_8( 1 , 2 , 3, 4 , 5 , 6 , 7 , 8 ) );
    EXPECT_CALL( o9,  c_fct_MOCK_9( 1 , 2 , 3, 4 , 5 , 6 , 7 , 8 , 9 ) );
    EXPECT_CALL( o10, c_fct_MOCK_10( 1 , 2 , 3, 4 , 5 , 6 , 7 , 8 , 9 , 10) );

    c_fct_MOCK_0_TEST( );
    c_fct_MOCK_1_TEST( 1 );
    c_fct_MOCK_2_TEST( 1, 2 );
    c_fct_MOCK_3_TEST( 1, 2, 3 );
    c_fct_MOCK_4_TEST( 1, 2, 3, 4 );
    c_fct_MOCK_5_TEST( 1, 2, 3, 4, 5 );
    c_fct_MOCK_6_TEST( 1, 2, 3, 4, 5, 6 );
    c_fct_MOCK_7_TEST( 1, 2, 3, 4, 5, 6, 7 );
    c_fct_MOCK_8_TEST( 1, 2, 3, 4, 5, 6, 7, 8 );
    c_fct_MOCK_9_TEST( 1, 2, 3, 4, 5, 6, 7, 8, 9 );
    c_fct_MOCK_10_TEST( 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 );
}



int  cxx_fct_to_mock00( );
int  cxx_fct_to_mock01( int );
void cxx_fct_to_mock02( int, int );
void cxx_fct_to_mock03( int, int, int );
void cxx_fct_to_mock04( int, int, int, int );
void cxx_fct_to_mock05( int, int, int, int, int );
void cxx_fct_to_mock06( int, int, int, int, int, int );
void cxx_fct_to_mock07( int, int, int, int, int, int, int );
void cxx_fct_to_mock08( int, int, int, int, int, int, int, int );
void cxx_fct_to_mock09( int, int, int, int, int, int, int, int, int );
void cxx_fct_to_mock10( int, int, int, int, int, int, int, int, int, int );
void cxx_fct_to_mock11 ( ) noexcept;


MOCK_FUNCTION(int,  cxx_fct_to_mock00, ()                                                  )
MOCK_FUNCTION(int , cxx_fct_to_mock01, (int)                                               )
MOCK_FUNCTION(void, cxx_fct_to_mock02, ( int, int)                                         )
MOCK_FUNCTION(void, cxx_fct_to_mock03, ( int, int, int)                                    )
MOCK_FUNCTION(void, cxx_fct_to_mock04, ( int, int, int, int)                               )
MOCK_FUNCTION(void, cxx_fct_to_mock05, ( int, int, int, int, int)                          )
MOCK_FUNCTION(void, cxx_fct_to_mock06, ( int, int, int, int, int, int)                     )
MOCK_FUNCTION(void, cxx_fct_to_mock07, ( int, int, int, int, int, int, int)                )
MOCK_FUNCTION(void, cxx_fct_to_mock08, ( int, int, int, int, int, int, int, int)           )
MOCK_FUNCTION(void, cxx_fct_to_mock09, ( int, int, int, int, int, int, int, int, int)      )
MOCK_FUNCTION(void, cxx_fct_to_mock10, ( int, int, int, int, int, int, int, int, int, int ))
MOCK_FUNCTION(void, cxx_fct_to_mock11, (), (noexcept));

int  cxx_fct00( )      { return cxx_fct_to_mock00( );  }
int  cxx_fct01( int a) { return cxx_fct_to_mock01( a );}
void cxx_fct02( int a, int b)   { cxx_fct_to_mock02( a , b ); }
void cxx_fct03( int a , int b, int c)                               { cxx_fct_to_mock03( a, b, c ); }
void cxx_fct04( int, int, int, int )                                { cxx_fct_to_mock04(1 ,2 ,3 ,4                   );  }
void cxx_fct05( int, int, int, int, int )                           { cxx_fct_to_mock05(1 ,2 ,3 ,4 ,5                );  }
void cxx_fct06( int, int, int, int, int, int )                      { cxx_fct_to_mock06(1 ,2 ,3 ,4 ,5 ,6             );  }
void cxx_fct07( int, int, int, int, int, int, int )                 { cxx_fct_to_mock07(1 ,2 ,3 ,4 ,5 ,6 ,7          );  }
void cxx_fct08( int, int, int, int, int, int, int, int )            { cxx_fct_to_mock08(1 ,2 ,3 ,4 ,5 ,6 ,7 ,8       );  }
void cxx_fct09( int, int, int, int, int, int, int, int, int )       { cxx_fct_to_mock09(1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9    );  }
void cxx_fct10( int, int, int, int, int, int, int, int, int, int )  { cxx_fct_to_mock10(1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10);  }
void cxx_fct11() noexcept { cxx_fct_to_mock11(); }

namespace MyTest
{
  void  cxx_fct_to_mock( );
  void  cxx_fct00( ) { cxx_fct_to_mock( ); }
}

namespace MyTest
{
MOCK_FUNCTION( void, cxx_fct_to_mock, () )
}


using namespace ::testing;

TEST( TestCaseName_1, TestName_0 )
{
    // 1st create the MOCK
    c_fct_to_mock_MOCK_TYPE & obj = c_fct_to_mock_MOCK_TYPE::Create( );

    // USE the MOCK
    EXPECT_CALL( obj, c_fct_to_mock( ) ).WillOnce( Return( 10 ) );
    EXPECT_EQ( my1st( 10, 20 ) , 10 + 20 + 10);
}
TEST( TestCaseName_1, TestName_1 )
{
    {
     InSequence dummy;
     c_fct_to_mock_MOCK_TYPE & obj = c_fct_to_mock_MOCK_TYPE::CreateStrict( );
     EXPECT_CALL( obj, c_fct_to_mock( ) )
        .WillOnce( Return( 60 ) );
    }
    EXPECT_EQ( my1st( 30, 40 ), 30 + 40 + 60 );
}
TEST( TestCaseName_1, TestName_2 )
{
  {
    c_fct_to_mock_MOCK_TYPE & obj  = c_fct_to_mock_MOCK_TYPE::CreateNice( );
    c_fct_to_mock2_MOCK_TYPE & obj2 = c_fct_to_mock2_MOCK_TYPE::CreateStrict( );
    InSequence dummy;
    EXPECT_CALL( obj, c_fct_to_mock( ) )
        .WillOnce( Return( 60 ) );
    EXPECT_CALL( obj2, c_fct_to_mock2( ) )
        .WillOnce( Return( 60 ) );
  }

  EXPECT_EQ( my2nd( 30, 40 ), 30 + 40 + 60 + 60 );
}
TEST( TestCaseName_1, TestName_3 )
{
  c_fct_to_mock3_MOCK_TYPE & obj = c_fct_to_mock3_MOCK_TYPE::Create( );
  EXPECT_CALL( obj, c_fct_to_mock3( 30 ) ).WillOnce( Return( 10 ) );
  EXPECT_EQ( my3rd( 10, 20 ), 10 );
}
TEST( TestCaseName_1, TestName_4 )
{
  c_fct_to_mock4_MOCK_TYPE & obj = c_fct_to_mock4_MOCK_TYPE::Create( );
  EXPECT_CALL( obj, c_fct_to_mock4( ) ).Times(1);
  EXPECT_NO_THROW( my4th( ) );
}
TEST( TestCaseName_1, TestName_5 )
{
  c_fct_to_mock5_MOCK_TYPE & obj = c_fct_to_mock5_MOCK_TYPE::Create( );
  EXPECT_CALL( obj, c_fct_to_mock5( ) ).Times( 1 );
  EXPECT_NO_THROW( my5th( ) );
}
TEST( TestCaseName_1, TestName_6 )
{
  c_fct_to_mock6_MOCK_TYPE & obj = c_fct_to_mock6_MOCK_TYPE::Create( );
  EXPECT_CALL( obj, c_fct_to_mock6( ) ).Times( 1 );
  EXPECT_NO_THROW( my6th( ) );
}
TEST( TestCaseName_1, TestName_7 )
{
   EXPECT_NONFATAL_FAILURE(
    {  EXPECT_THROW(  my7th( ), std::runtime_error ); }
   ,  "\nPLEASE CREATE MOCK OBJECT FOR FUNCTION c_fct_to_mock7 IN TEST( TestCaseName_1 , TestName_7 )"
      "\n Use ONE of the following code lines:\n"
      "  auto & naggyMock  = c_fct_to_mock7_MOCK_TYPE::Create( );\n"
      "  auto & strictMock = c_fct_to_mock7_MOCK_TYPE::CreateStrict( );\n"
      "  auto & niceMock   = c_fct_to_mock7_MOCK_TYPE::CreateNice( );\n"
   );
}
TEST( TestCaseName_1, TestName_8 )
{
   EXPECT_NONFATAL_FAILURE(
    {  EXPECT_THROW( my6th( ), std::runtime_error ); }
   ,  "\nPLEASE CREATE MOCK OBJECT FOR FUNCTION c_fct_to_mock6 IN TEST( TestCaseName_1 , TestName_8 )"
      "\n Use ONE of the following code lines:\n"
      "  auto & naggyMock  = c_fct_to_mock6_MOCK_TYPE::Create( );\n"
      "  auto & strictMock = c_fct_to_mock6_MOCK_TYPE::CreateStrict( );\n"
      "  auto & niceMock   = c_fct_to_mock6_MOCK_TYPE::CreateNice( );\n"
   );
}

TEST( TestCxxFct, all_test )
{
   cxx_fct_to_mock00_MOCK_TYPE & moc00 = cxx_fct_to_mock00_MOCK_TYPE::CreateStrict( );
   cxx_fct_to_mock01_MOCK_TYPE & moc01 = cxx_fct_to_mock01_MOCK_TYPE::CreateStrict( );
   cxx_fct_to_mock02_MOCK_TYPE & moc02 = cxx_fct_to_mock02_MOCK_TYPE::CreateStrict( );
   cxx_fct_to_mock03_MOCK_TYPE & moc03 = cxx_fct_to_mock03_MOCK_TYPE::CreateStrict( );
   cxx_fct_to_mock04_MOCK_TYPE & moc04 = cxx_fct_to_mock04_MOCK_TYPE::CreateStrict( );
   cxx_fct_to_mock05_MOCK_TYPE & moc05 = cxx_fct_to_mock05_MOCK_TYPE::CreateStrict( );
   cxx_fct_to_mock06_MOCK_TYPE & moc06 = cxx_fct_to_mock06_MOCK_TYPE::CreateStrict( );
   cxx_fct_to_mock07_MOCK_TYPE & moc07 = cxx_fct_to_mock07_MOCK_TYPE::CreateStrict( );
   cxx_fct_to_mock08_MOCK_TYPE & moc08 = cxx_fct_to_mock08_MOCK_TYPE::CreateStrict( );
   cxx_fct_to_mock09_MOCK_TYPE & moc09 = cxx_fct_to_mock09_MOCK_TYPE::CreateStrict( );
   cxx_fct_to_mock10_MOCK_TYPE & moc10 = cxx_fct_to_mock10_MOCK_TYPE::CreateStrict( );
   cxx_fct_to_mock11_MOCK_TYPE & moc11 = cxx_fct_to_mock11_MOCK_TYPE::CreateStrict( );

   {
     InSequence dummy;
     EXPECT_CALL( moc00, cxx_fct_to_mock00( ) );
     EXPECT_CALL( moc01, cxx_fct_to_mock01( 1                                         ) );
     EXPECT_CALL( moc02, cxx_fct_to_mock02( 1 ,  2                                    ) );
     EXPECT_CALL( moc03, cxx_fct_to_mock03( 1 ,  2 ,  3                               ) );
     EXPECT_CALL( moc04, cxx_fct_to_mock04( 1 ,  2 ,  3 ,  4                          ) );
     EXPECT_CALL( moc05, cxx_fct_to_mock05( 1 ,  2 ,  3 ,  4 ,  5                     ) );
     EXPECT_CALL( moc06, cxx_fct_to_mock06( 1 ,  2 ,  3 ,  4 ,  5 , 6                 ) );
     EXPECT_CALL( moc07, cxx_fct_to_mock07( 1 ,  2 ,  3 ,  4 ,  5 , 6 , 7             ) );
     EXPECT_CALL( moc08, cxx_fct_to_mock08( 1 ,  2 ,  3 ,  4 ,  5 , 6 , 7 , 8         ) );
     EXPECT_CALL( moc09, cxx_fct_to_mock09( 1 ,  2 ,  3 ,  4 ,  5 , 6 , 7 , 8 , 9     ) );
     EXPECT_CALL( moc10, cxx_fct_to_mock10( 1 ,  2 ,  3 ,  4 ,  5 , 6 , 7 , 8 , 9 , 10) );
     EXPECT_CALL( moc11, cxx_fct_to_mock11() );
   }

   cxx_fct00( );
   cxx_fct01( 1 );
   cxx_fct02( 1, 2 );
   cxx_fct03( 1, 2, 3 );
   cxx_fct04( 1, 2, 3, 4 );
   cxx_fct05( 1, 2, 3, 4, 5 );
   cxx_fct06( 1, 2, 3, 4, 5, 6 );
   cxx_fct07( 1, 2, 3, 4, 5, 6, 7 );
   cxx_fct08( 1, 2, 3, 4, 5, 6, 7, 8 );
   cxx_fct09( 1, 2, 3, 4, 5, 6, 7, 8, 9 );
   cxx_fct10( 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 );
   cxx_fct11( );
}

TEST( TestCxxFct, WithNameSpace )
{
    using MyTest::cxx_fct_to_mock;

    auto & moc = MyTest::cxx_fct_to_mock_MOCK_TYPE::CreateStrict( );

    EXPECT_CALL( moc, cxx_fct_to_mock( ) );

    MyTest::cxx_fct00();
}


void cxxtest1( int );
void cxxtest1( bool ) noexcept;


MOCK_FUNCTION_OVERLOAD( 1, void, cxxtest1, (int) )
MOCK_FUNCTION_OVERLOAD( 2, void, cxxtest1, (bool), (noexcept) )

TEST( CXX_OVL_FUNCTION, _1 )
{
    auto & o0 = cxxtest1_MOCK_TYPE1::CreateStrict( );
    auto & o1 = cxxtest1_MOCK_TYPE2::CreateStrict( );
    EXPECT_CALL( o0, cxxtest1( 10 ) );
    EXPECT_CALL( o1, cxxtest1( true ) );
    cxxtest1( 10 );
    cxxtest1( true );
}

struct ClsObject
{
    bool execute1();
    bool execute2(int);
    bool execute3(bool);
    bool execute4(double) const;
    ~ClsObject();
    ClsObject();
    ClsObject(int);
};

MOCK_CLASS_CTOR(ClsObject, ,())
MOCK_CLASS_CTOR(ClsObject,1,(int))
MOCK_CLASS_DTOR(ClsObject)
MOCK_CLASS_METHOD(ClsObject, bool, execute1, ())
MOCK_CLASS_METHOD(ClsObject, bool, execute2, (int))
MOCK_CLASS_METHOD(ClsObject, bool, execute3, (bool))
MOCK_CLASS_METHOD(ClsObject, bool, execute4, (double), (const))


TEST(MEMBER_FUNCTION, _3)
{
    auto& o0 = ClsObject_ctor_MOCK_TYPE::CreateStrict();
    auto& o1 = ClsObject_ctor_MOCK_TYPE1::CreateStrict();
    auto& o2 = ClsObject_dtor_MOCK_TYPE::CreateStrict();
    auto& o3 = ClsObject_execute1_MOCK_TYPE::CreateStrict();
    auto& o4 = ClsObject_execute2_MOCK_TYPE::CreateStrict();
    auto& o5 = ClsObject_execute3_MOCK_TYPE::CreateStrict();
    auto& o6 = ClsObject_execute4_MOCK_TYPE::CreateStrict();
    


    EXPECT_CALL(o0, ctor()).Times(3);
    EXPECT_CALL(o1, ctor(10)).Times(1);
    EXPECT_CALL(o2, dtor()).Times(4);
    EXPECT_CALL(o3, execute1());
    EXPECT_CALL(o4, execute2(10));
    EXPECT_CALL(o5, execute3(true));
    EXPECT_CALL(o6, execute4(10.0));
    

    ClsObject().execute1();
    ClsObject().execute2(10);
    ClsObject().execute3(true);
    const ClsObject obj(10);
    obj.execute4(10.0);
}

struct ClsObjectExtended
{
    bool execute();
    bool execute(int);
    bool execute(bool);
    bool execute(double) const;
};

MOCK_CLASS_METHOD_OVERLOAD(ClsObjectExtended, 1, bool, execute, ())
MOCK_CLASS_METHOD_OVERLOAD(ClsObjectExtended, 2, bool, execute, (int))
MOCK_CLASS_METHOD_OVERLOAD(ClsObjectExtended, 3, bool, execute, (bool))
MOCK_CLASS_METHOD_OVERLOAD(ClsObjectExtended, 4, bool, execute, (double), (const))

TEST(MEMBER_FUNCTION, _2)
{
    auto& o1 = ClsObjectExtended_execute_MOCK_TYPE1::CreateStrict();
    auto& o2 = ClsObjectExtended_execute_MOCK_TYPE2::CreateStrict();
    auto& o3 = ClsObjectExtended_execute_MOCK_TYPE3::CreateStrict();
    auto& o4 = ClsObjectExtended_execute_MOCK_TYPE4::CreateStrict();

    EXPECT_CALL(o1, execute());
    EXPECT_CALL(o2, execute(10));
    EXPECT_CALL(o3, execute(true));
    EXPECT_CALL(o4, execute(10.0));

    ClsObjectExtended().execute();
    ClsObjectExtended().execute(10);
    ClsObjectExtended().execute(true);
    const ClsObjectExtended obj;
    obj.execute(10.0);
}

