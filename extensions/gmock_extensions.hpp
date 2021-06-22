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
#ifndef gmock_extensions__HH_INLCUDE_GUARD
#define gmock_extensions__HH_INLCUDE_GUARD

/* MACROS:
*       MOCK_FUNCTION
*       MOCK_FUNCTION_OVERLOAD
*
*       MOCK_CLASS_CTOR
*       MOCK_CLASS_DTOR
*       MOCK_CLASS_METHOD
*       MOCK_CLASS_METHOD_OVERLOAD
*
*/
#include <gtest/gtest.h>
#include <gmock/gmock.h>

/* \def MOCK_FUNCTION(...)
*  \brief generate mocks for free functions
*  \param [in] ... 1st ReturnType       e.g.: int or (std::pair<int,bool>) optional paracentesis if type contains comma
*                  2nd FunctionName     e.g.: myFunctionName
*                  3rd Arguments        e.g.: (int, char *, uint16_t t)    always require paracentesis
*                  4th Specs (noexcept) e.g.: (noexcept)                   always require paracentesis [OPTIONAL]
*   \details
*       void c_fct_MOCK_0();
*       void c_fct_MOCK_1(int);
*       void c_fct_MOCK_0_TEST  ( )        { c_fct_MOCK_0 ( );     }
*       void c_fct_MOCK_1_TEST  ( int a0 ) { c_fct_MOCK_1  ( a0 ); }
*
*       MOCK_FUNCTION(void, c_fct_MOCK_0, ());
*       MOCK_FUNCTION(void, c_fct_MOCK_1, (int));
*
*       TEST( C_FUNCTIONS, paramterForwarding )
*       {
*           // 1st create the MOCK
*           auto  & o0  = c_fct_MOCK_0_MOCK_TYPE::CreateStrict( );
*           auto  & o1  = c_fct_MOCK_1_MOCK_TYPE::CreateStrict( );
*           
*           EXPECT_CALL( o0,  c_fct_MOCK_0( ) );
*           EXPECT_CALL( o1,  c_fct_MOCK_1( 1 ) );
*
*           c_fct_MOCK_0_TEST( );
*           c_fct_MOCK_1_TEST( 1 );
*       }
*/
#define MOCK_FUNCTION(...) \
  GMOCK_PP_VARIADIC_CALL(GMOCK_EXTENSION_FUNCTION_INTERNAL_ARG_, __VA_ARGS__)

/* \def MOCK_FUNCTION_OVERLOAD(...)
*  \brief generate mocks for free functions
*  \param [in] ... 1st overloadId       e.g.: 0
*                  2nd ReturnType       e.g.: int or (std::pair<int,bool>) optional paracentesis if type contains comma
*                  3rd FunctionName     e.g.: myFunctionName
*                  4th Arguments        e.g.: (int, char *, uint16_t t)    always require paracentesis
*                  5th Specs (noexcept) e.g.: (noexcept)                   always require paracentesis [OPTIONAL]
*   \details
*      void cxxtest1( int );
*      void cxxtest1( bool );
*
*      MOCK_FUNCTION_OVERLOAD( 1, void, cxxtest1, (int) )
*      MOCK_FUNCTION_OVERLOAD( 2, void, cxxtest1, (bool) )
*
*      TEST( CXX_OVL_FUNCTION, _1 )
*      {
*          auto & o0 = cxxtest1_MOCK_TYPE1::CreateStrict( );
*          auto & o1 = cxxtest1_MOCK_TYPE2::CreateStrict( );
*          EXPECT_CALL( o0, cxxtest1( 10 ) );
*          EXPECT_CALL( o1, cxxtest1( true ) );
*          cxxtest1( 10 );
*          cxxtest1( true );
*      }
*/
#define MOCK_FUNCTION_OVERLOAD(...) \
  GMOCK_PP_VARIADIC_CALL(GMOCK_EXTENSION_FUNCTION_OVERLOAD_INTERNAL_ARG_, __VA_ARGS__)

/* \def MOCK_CLASS_METHOD(...)
*  \brief generate mocks for free functions
*  \param [in] ... 1st class
*                  2nd ReturnType       e.g.: int or (std::pair<int,bool>) optional paracentesis if type contains comma
*                  3rd FunctionName     e.g.: myFunctionName
*                  4th Arguments        e.g.: (int, char *, uint16_t t)    always require paracentesis
*                  5th Specs (noexcept) e.g.: (noexcept)                   always require paracentesis [OPTIONAL]
*   \details
*      struct SpamExtended
*      {
*          bool execute0();
*          bool execute1(int);
*          bool execute2(bool);
*          bool execute3(double) const;
*      };
*
*      MOCK_CLASS_METHOD(SpamExtended, bool, execute0 )
*      MOCK_CLASS_METHOD(SpamExtended, bool, execute1, (int))
*      MOCK_CLASS_METHOD(SpamExtended, bool, execute2, (bool))
*      MOCK_CLASS_METHOD(SpamExtended, bool, execute3, (double), (const))
*/
#define MOCK_CLASS_METHOD(...) \
  GMOCK_PP_VARIADIC_CALL(GMOCK_EXTENSION_CLASS_METHOD_INTERNAL_ARG_, __VA_ARGS__)

/* \def MOCK_CLASS_METHOD_OVERLOAD(...)
*  \brief generate mocks for free functions
*  \param [in] ... 1st class
*                  2nd overloadId       e.g.: 0
*                  3rd ReturnType       e.g.: int or (std::pair<int,bool>) optional paracentesis if type contains comma
*                  4th FunctionName     e.g.: myFunctionName
*                  5th Arguments        e.g.: (int, char *, uint16_t t)    always require paracentesis
*                  6th Specs (noexcept) e.g.: (noexcept)                   always require paracentesis [OPTIONAL]
*   \details
*      struct Spam1
*      {
*          bool execute1();
*          bool execute2(int);
*          bool execute3(bool);
*          bool execute4(double) const;
*      };
*      
*      MOCK_CLASS_METHOD(Spam1, bool, execute1)
*      MOCK_CLASS_METHOD(Spam1, bool, execute2, (int))
*      MOCK_CLASS_METHOD(Spam1, bool, execute3, (bool))
*      MOCK_CLASS_METHOD(Spam1, bool, execute4, (double), (const))
*      
*      TEST(MEMBER_FUNCTION, _3)
*      {
*          auto& o1 = Spam1_execute1_MOCK_TYPE::CreateStrict();
*          auto& o2 = Spam1_execute2_MOCK_TYPE::CreateStrict();
*          auto& o3 = Spam1_execute3_MOCK_TYPE::CreateStrict();
*          auto& o4 = Spam1_execute4_MOCK_TYPE::CreateStrict();
*      
*          EXPECT_CALL(o1, execute1());
*          EXPECT_CALL(o2, execute2(10));
*          EXPECT_CALL(o3, execute3(true));
*          EXPECT_CALL(o4, execute4(10.0));
*      
*          Spam1().execute1();
*          Spam1().execute2(10);
*          Spam1().execute3(true);
*          const Spam1 obj;
*          obj.execute4(10.0);
*      }
*/
#define MOCK_CLASS_METHOD_OVERLOAD(...) \
  GMOCK_PP_VARIADIC_CALL(GMOCK_EXTENSION_CLASS_METHOD_OVERLOAD_INTERNAL_ARG_, __VA_ARGS__)

/** \def MOCK_CLASS_CTOR( ... )
*  \brief generate mocks for ctor's
*
*  \param [in] CLASS  class name that contains the ctor
*  \param [in] ...
*                 2nd overloadId       e.g.: 0 [optional] could be empty
*                 3rd Arguments        e.g.: (int, char *, uint16_t t)    always require paracentesis
*                 4th Specs (noexcept) e.g.: (noexcept)                   always require paracentesis
*  \details
*        struct Spam1
*        {
*            Spam1();
*            Spam1(int);
*        };
*
*        MOCK_CLASS_CTOR(Spam1, ,())
*        MOCK_CLASS_CTOR(Spam1,1,(int))
*
*        TEST(MEMBER_FUNCTION, _3)
*        {
*            auto& o0 = Spam1_ctor_MOCK_TYPE::CreateStrict();
*            auto& o1 = Spam1_ctor_MOCK_TYPE1::CreateStrict();
*
*            EXPECT_CALL(o0, ctor()).Times(3);
*            EXPECT_CALL(o1, ctor(10)).Times(1);
*
*            Spam1 a, b, c;
*            const Spam1 obj(10);
*        }
*/
#define MOCK_CLASS_CTOR(  ...  ) \
  GMOCK_PP_VARIADIC_CALL(GMOCK_EXTENSION_CLASS_CTOR_INTERNAL_ARG_, __VA_ARGS__)

/** \def MOCK_CLASS_DTOR( ... )
*  \brief generate mocks for Dtor
*
*  \param [in] CLASS  class name that contains the Dtor
*  \param [in] ...
*                 2nd Specs (noexcept) e.g.: (noexcept)  always require paracentesis [OPTIONAL]
*  \details
*        struct Spam
*        {
*            ~Spam1();
*        };
*
*        MOCK_CLASS_DTOR(Spam)
*
*        TEST(MEMBER_FUNCTION, _3)
*        {
*            auto& o0 = Spam_dtor_MOCK_TYPE::CreateStrict();
*
*            EXPECT_CALL(o0, dtor()).Times(4);
*
*            Spam a, b, c;
*            const Spam obj(10);
*        }
*/
#define MOCK_CLASS_DTOR( ... ) \
  GMOCK_PP_VARIADIC_CALL(GMOCK_EXTENSION_CLASS_DTOR_ARG_, __VA_ARGS__ )



// implementation details
namespace TestingExtension
{
    class IMockBase {
        static int genId();
        int id;
    public:
        IMockBase();
        virtual ~IMockBase();
        virtual void Reset() const = 0;
        int GetId();
    };
    class MockVerifyAndClearExpectation : public ::testing::EmptyTestEventListener
    {
    public:
        virtual void OnTestStart(::testing::TestInfo const&);
        virtual void OnTestEnd(::testing::TestInfo const&);
        virtual void OnTestProgramEnd(::testing::UnitTest const&);

        static void  add(IMockBase* obj);
        static void  remove(IMockBase* obj);
    };
}

#define PpTestName     ::testing::UnitTest::GetInstance( )->current_test_info( )->name( )
#define PpTestCaseName ::testing::UnitTest::GetInstance( )->current_test_info( )->test_case_name( )
#define PpMockName(FUNC_NAME, overloadId)      GMOCK_PP_CAT(GMOCK_PP_CAT( FUNC_NAME, _MOCK_TYPE ), overloadId)

#define PpMockAccessHead( FUNC_NAME, overloadId )                                                  \
  struct PpMockName(FUNC_NAME, overloadId) : public ::TestingExtension::IMockBase {

#define PpMockAccessTail( FUNC_NAME, overloadId)                                                   \
     static PpMockName(FUNC_NAME, overloadId) & Create( )                                          \
     {                                                                                             \
        Replace( new PpMockName(FUNC_NAME, overloadId) );                                          \
        return *GetPtr( );                                                                         \
     }                                                                                             \
     static PpMockName(FUNC_NAME, overloadId) & CreateStrict( )                                    \
     {                                                                                             \
        Replace( new ::testing::StrictMock< PpMockName(FUNC_NAME, overloadId) > );                 \
        return *GetPtr( );                                                                         \
     }                                                                                             \
     static PpMockName(FUNC_NAME, overloadId) & CreateNice( )                                      \
     {                                                                                             \
        Replace( new ::testing::NiceMock< PpMockName(FUNC_NAME, overloadId) > );                   \
        return *GetPtr( );                                                                         \
     }                                                                                             \
     static PpMockName(FUNC_NAME, overloadId) * & GetPtr( )                                        \
     {                                                                                             \
        static PpMockName(FUNC_NAME, overloadId) * tmp;                                            \
        return tmp;                                                                                \
     }                                                                                             \
     static void AssertWhenNotInit( )                                                              \
     {                                                                                             \
       void * ptr_to_mock_obj = GetPtr( );                                                         \
       EXPECT_TRUE( ptr_to_mock_obj ) <<                                                           \
         "\nPLEASE CREATE MOCK OBJECT FOR FUNCTION " GMOCK_PP_STRINGIZE( FUNC_NAME )               \
         " IN TEST( " <<  PpTestCaseName << " , " << PpTestName << " )"                            \
         "\n Use ONE of the following code lines:\n"                                               \
         "  auto & naggyMock  = "                                                                  \
            GMOCK_PP_STRINGIZE(PpMockName(FUNC_NAME, overloadId)) "::Create( );\n"                 \
         "  auto & strictMock = "                                                                  \
            GMOCK_PP_STRINGIZE(PpMockName(FUNC_NAME, overloadId)) "::CreateStrict( );\n"           \
         "  auto & niceMock   = "                                                                  \
            GMOCK_PP_STRINGIZE(PpMockName(FUNC_NAME, overloadId)) "::CreateNice( );\n";            \
       if( !ptr_to_mock_obj )                                                                      \
           throw std::runtime_error("MISSING MOCK OBJECT FOR THE FUNCTION "                        \
                                      GMOCK_PP_STRINGIZE(FUNC_NAME));                              \
     }                                                                                             \
     virtual void Reset( ) const                                                                   \
     {                                                                                             \
       GetPtr( ) = nullptr;                                                                        \
     }                                                                                             \
  private:                                                                                         \
   static void Replace( PpMockName(FUNC_NAME, overloadId) * p )                                    \
   {                                                                                               \
     auto * tmp = GetPtr( );                                                                       \
     if( tmp ) {                                                                                   \
         ::TestingExtension::MockVerifyAndClearExpectation::remove( tmp );                         \
         delete tmp;                                                                               \
     }                                                                                             \
     GetPtr( ) = p;                                                                                \
     ::TestingExtension::MockVerifyAndClearExpectation::add( p );                                  \
   }                                                                                               \
  };

#define GMOCK_EXTENSION_FUNCTION_INTERNAL_ARG_1(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_FUNCTION_INTERNAL_ARG_2(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_FUNCTION_INTERNAL_ARG_3(_Ret, _FunctionName, _Args)        \
  PpMockAccessHead( _FunctionName, )                                               \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_3( _Ret, _FunctionName, _Args );                  \
  PpMockAccessTail( _FunctionName, )                                               \
    GMOCK_EXTENSION_FUNCTION_INTERNAL( GMOCK_PP_NARG0 _Args, _FunctionName, , , ,  \
      (GMOCK_INTERNAL_SIGNATURE(_Ret, _Args)) )

#define GMOCK_EXTENSION_FUNCTION_INTERNAL_ARG_4(_Ret, _FunctionName, _Args, _Spec) \
  PpMockAccessHead( _FunctionName, )                                               \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_4( _Ret, _FunctionName, _Args, _Spec );           \
  PpMockAccessTail( _FunctionName, )                                               \
  GMOCK_EXTENSION_FUNCTION_INTERNAL( GMOCK_PP_NARG0 _Args, _FunctionName, ,        \
      GMOCK_INTERNAL_GET_NOEXCEPT_SPEC(_Spec),                                     \
      GMOCK_INTERNAL_GET_CALLTYPE(_Spec),                                          \
      (GMOCK_INTERNAL_SIGNATURE(_Ret, _Args)) )

#define GMOCK_EXTENSION_FUNCTION_OVERLOAD_INTERNAL_ARG_1(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_FUNCTION_OVERLOAD_INTERNAL_ARG_2(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_FUNCTION_OVERLOAD_INTERNAL_ARG_3(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_FUNCTION_OVERLOAD_INTERNAL_ARG_4(overloadId, _Ret, _FunctionName, _Args) \
  PpMockAccessHead( _FunctionName, overloadId)                                                   \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_3( _Ret, _FunctionName, _Args );                                \
  PpMockAccessTail( _FunctionName, overloadId)                                                   \
  GMOCK_EXTENSION_FUNCTION_INTERNAL( GMOCK_PP_NARG0 _Args, _FunctionName, overloadId, , ,        \
                                     (GMOCK_INTERNAL_SIGNATURE(_Ret, _Args)))

#define GMOCK_EXTENSION_FUNCTION_OVERLOAD_INTERNAL_ARG_5(overloadId, _Ret, _FunctionName, _Args, _Spec) \
  PpMockAccessHead( _FunctionName, overloadId)                                                   \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_4( _Ret, _FunctionName, _Args, _Spec );                         \
  PpMockAccessTail( _FunctionName, overloadId)                                                   \
  GMOCK_EXTENSION_FUNCTION_INTERNAL( GMOCK_PP_NARG0 _Args, _FunctionName, overloadId,            \
      GMOCK_INTERNAL_GET_NOEXCEPT_SPEC(_Spec), GMOCK_INTERNAL_GET_CALLTYPE(_Spec),               \
      (GMOCK_INTERNAL_SIGNATURE(_Ret, _Args)))

#define GMOCK_EXTENSION_FUNCTION_INTERNAL( _N, _FunctionName, overloadId,            \
                                 _Noexcept, _CallType, _Signature)                   \
  typename ::testing::internal::Function<GMOCK_PP_REMOVE_PARENS(_Signature)>::Result \
   GMOCK_INTERNAL_EXPAND(_CallType)                                                  \
  _FunctionName(GMOCK_PP_REPEAT(GMOCK_INTERNAL_PARAMETER, _Signature, _N)) _Noexcept \
  {                                                                                  \
    PpMockName(_FunctionName, overloadId)::AssertWhenNotInit();                      \
    return PpMockName(_FunctionName, overloadId)::GetPtr( )->_FunctionName(          \
            GMOCK_PP_REPEAT(GMOCK_INTERNAL_FORWARD_ARG, _Signature, _N));            \
  }

#define GMOCK_EXTENSION_CLASS_METHOD_INTERNAL_ARG_1(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_CLASS_METHOD_INTERNAL_ARG_2(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_CLASS_METHOD_INTERNAL_ARG_3(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_CLASS_METHOD_INTERNAL_ARG_4(_class, _Ret, _FunctionName, _Args)     \
  PpMockAccessHead( _class##_##_FunctionName, )                                             \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_3( _Ret, _FunctionName, _Args );                           \
  PpMockAccessTail( _class##_##_FunctionName, )                                             \
  GMOCK_EXTENSION_CLASS_METHOD_INTERNAL( GMOCK_PP_NARG0 _Args, _class, _FunctionName, ,     \
       0 , , , 0, 0, , (GMOCK_INTERNAL_SIGNATURE(_Ret, _Args)))

#define GMOCK_EXTENSION_CLASS_METHOD_INTERNAL_ARG_5(_class, _Ret, _FunctionName, _Args, _Spec)  \
  PpMockAccessHead( _class##_##_FunctionName, )                                         \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_4( _Ret, _FunctionName, _Args, _Spec );                \
  PpMockAccessTail( _class##_##_FunctionName, )                                         \
  GMOCK_EXTENSION_CLASS_METHOD_INTERNAL( GMOCK_PP_NARG0 _Args, _class, _FunctionName, , \
      GMOCK_INTERNAL_HAS_CONST(_Spec),                                                  \
      GMOCK_INTERNAL_GET_NOEXCEPT_SPEC(_Spec),                                          \
      GMOCK_INTERNAL_GET_REF_SPEC(_Spec),                                               \
      GMOCK_INTERNAL_HAS_OVERRIDE(_Spec),                                               \
      GMOCK_INTERNAL_HAS_FINAL(_Spec),                                                  \
      GMOCK_INTERNAL_GET_CALLTYPE(_Spec),                                               \
      (GMOCK_INTERNAL_SIGNATURE(_Ret, _Args)))

#define GMOCK_EXTENSION_CLASS_METHOD_OVERLOAD_INTERNAL_ARG_1(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_CLASS_METHOD_OVERLOAD_INTERNAL_ARG_2(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_CLASS_METHOD_OVERLOAD_INTERNAL_ARG_3(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_CLASS_METHOD_OVERLOAD_INTERNAL_ARG_4(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_CLASS_METHOD_OVERLOAD_INTERNAL_ARG_5(_class, overloadId, _Ret, _FunctionName, _Args) \
  PpMockAccessHead( _class##_##_FunctionName, overloadId)                                                    \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_3( _Ret, _FunctionName, _Args );                                            \
  PpMockAccessTail( _class##_##_FunctionName, overloadId)                                                    \
  GMOCK_EXTENSION_CLASS_METHOD_INTERNAL( GMOCK_PP_NARG0 _Args, _class, _FunctionName, overloadId,            \
       0 , , , 0, 0, , (GMOCK_INTERNAL_SIGNATURE(_Ret, _Args)))

#define GMOCK_EXTENSION_CLASS_METHOD_OVERLOAD_INTERNAL_ARG_6(_class, overloadId, _Ret, _FunctionName, _Args, _Spec) \
  PpMockAccessHead( _class##_##_FunctionName, overloadId)                                                           \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_4( _Ret, _FunctionName, _Args, _Spec );                                            \
  PpMockAccessTail( _class##_##_FunctionName, overloadId)                                                           \
  GMOCK_EXTENSION_CLASS_METHOD_INTERNAL( GMOCK_PP_NARG0 _Args, _class, _FunctionName, overloadId,                   \
      GMOCK_INTERNAL_HAS_CONST(_Spec),                                                                              \
      GMOCK_INTERNAL_GET_NOEXCEPT_SPEC(_Spec),                                                                      \
      GMOCK_INTERNAL_GET_REF_SPEC(_Spec),                                                                           \
      GMOCK_INTERNAL_HAS_OVERRIDE(_Spec),                                                                           \
      GMOCK_INTERNAL_HAS_FINAL(_Spec),                                                                              \
      GMOCK_INTERNAL_GET_CALLTYPE(_Spec),                                                                           \
      (GMOCK_INTERNAL_SIGNATURE(_Ret, _Args)))


#define GMOCK_EXTENSION_CLASS_METHOD_INTERNAL( _N, _Class, _FunctionName, overloadId,           \
                                  _Const, _Noexcept, _RefSpec, _Override, _Final, _CallType, _Signature)  \
  typename ::testing::internal::Function<GMOCK_PP_REMOVE_PARENS(_Signature)>::Result            \
   GMOCK_INTERNAL_EXPAND(_CallType)                                                             \
  _Class::_FunctionName(GMOCK_PP_REPEAT(GMOCK_INTERNAL_PARAMETER, _Signature, _N))              \
   GMOCK_PP_IF(_Const,    const   , )                                                           \
   _RefSpec _Noexcept                                                                           \
   GMOCK_PP_IF(_Override, override, )                                                           \
   GMOCK_PP_IF(_Final,    final, ) {                                                            \
    PpMockName(_Class##_##_FunctionName, overloadId)::AssertWhenNotInit();                      \
    return PpMockName(_Class##_##_FunctionName, overloadId)::GetPtr( )->_FunctionName(          \
            GMOCK_PP_REPEAT(GMOCK_INTERNAL_FORWARD_ARG, _Signature, _N));                       \
  }

#define GMOCK_EXTENSION_CLASS_DTOR_ARG_1(CLASS)          \
  PpMockAccessHead( CLASS##_dtor, )                      \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_3( void, dtor, ());     \
  PpMockAccessTail( CLASS##_dtor, )                      \
    CLASS::~CLASS( )                                     \
    {   PpMockName(CLASS##_dtor, )::AssertWhenNotInit(); \
        PpMockName(CLASS##_dtor, )::GetPtr()->dtor( );   \
    }

#define GMOCK_EXTENSION_CLASS_DTOR_ARG_2(CLASS, _spec )        \
  PpMockAccessHead( CLASS##_dtor, )                            \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_3( void, dtor, () );          \
  PpMockAccessTail( CLASS##_dtor, )                            \
    CLASS::~CLASS( )                                           \
    GMOCK_INTERNAL_GET_NOEXCEPT_SPEC(_Spec)                    \
    {   PpMockName(CLASS##_dtor, )::AssertWhenNotInit();       \
        PpMockName(CLASS##_dtor, )::GetPtr()->dtor( );         \
    }

#define GMOCK_EXTENSION_CLASS_CTOR_INTERNAL_ARG_1(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_CLASS_CTOR_INTERNAL_ARG_2(...) \
  GMOCK_INTERNAL_WRONG_ARITY(__VA_ARGS__)

#define GMOCK_EXTENSION_CLASS_CTOR_INTERNAL_ARG_3(_class, overloadId, _Args)        \
  PpMockAccessHead( _class##_ctor, overloadId)                                      \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_3( void, ctor , _Args );                           \
  PpMockAccessTail( _class##_ctor, overloadId)                                      \
  GMOCK_EXTENSION_CLASS_CTOR_INTERNAL( GMOCK_PP_NARG0 _Args, _class, overloadId,    \
         , , (GMOCK_INTERNAL_SIGNATURE(void, _Args)))

#define GMOCK_EXTENSION_CLASS_CTOR_INTERNAL_ARG_4(_class, overloadId, _Args, _Spec)  \
  PpMockAccessHead( _class##_ctor, overloadId)                                       \
  GMOCK_INTERNAL_MOCK_METHOD_ARG_4( void, ctor, _Args, _Spec );                      \
  PpMockAccessTail( _class##_ctor, overloadId)                                       \
  GMOCK_EXTENSION_CLASS_CTOR_INTERNAL( GMOCK_PP_NARG0 _Args, _class, overloadId,     \
      GMOCK_INTERNAL_GET_NOEXCEPT_SPEC(_Spec),                                       \
      GMOCK_INTERNAL_GET_CALLTYPE(_Spec),                                            \
      (GMOCK_INTERNAL_SIGNATURE(void, _Args)))


#define GMOCK_EXTENSION_CLASS_CTOR_INTERNAL( _N, _Class, overloadId, _Noexcept, \
                                            _CallType, _Signature)              \
   GMOCK_INTERNAL_EXPAND(_CallType)                                             \
   _Class::_Class(GMOCK_PP_REPEAT(GMOCK_INTERNAL_PARAMETER, _Signature, _N))    \
   _Noexcept                                                                    \
   {                                                                            \
    PpMockName(_Class##_ctor, overloadId)::AssertWhenNotInit();                 \
    PpMockName(_Class##_ctor, overloadId)::GetPtr( )->ctor(                     \
            GMOCK_PP_REPEAT(GMOCK_INTERNAL_FORWARD_ARG, _Signature, _N));       \
   }

#endif
