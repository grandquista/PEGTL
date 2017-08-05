// Copyright (c) 2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#include "test.hpp"

#include <sstream>

namespace tao
{
   namespace TAOCPP_PEGTL_NAMESPACE
   {
      void unit_test()
      {
         std::string data( "(.)" );
         verify_rule< seq< one< '(' >, discard, must< one< ')' > > > >( __LINE__, __FILE__, data, result_type::GLOBAL_FAILURE, 2 );
         std::stringstream stream( data );
         istream_input<> in( stream, 3, __FILE__ );
         verify_input< seq< one< '(' >, discard, must< one< ')' > > > >( __LINE__, __FILE__, data, in, result_type::GLOBAL_FAILURE, 2 );
         std::stringstream stream2( data );
         istream_input<> i2( stream2, 3, __FILE__ );
         verify_input< seq< one< '(' >, discard, one< ')' > > >( __LINE__, __FILE__, data, in, result_type::LOCAL_FAILURE, 2 );
      }

   }  // namespace TAOCPP_PEGTL_NAMESPACE

}  // namespace tao

#include "main.hpp"
