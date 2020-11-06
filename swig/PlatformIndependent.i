%module RTDE_MODULE


%feature("nspace");

%warnfilter(322) MAJOR_VERSION;
%warnfilter(322) CB3_MAJOR_VERSION;

%include "std_shared_ptr.i";
%include "std_string.i";
%include "arrays_java.i";
%include "std_vector.i"
%include "stdint.i";

%include "typemaps.i";
%apply uint32_t& INOUT { uint32_t& };

%template(VectorDouble) std::vector<double>;
%template(VectorInt) std::vector<int>;
%template(VectorVectorDouble) std::vector<std::vector<double>>;
%template(VectorString) std::vector<std::string>;
%template(VectorChar) std::vector<char>;
%template(SharedPtrService) std::shared_ptr<boost::asio::io_service> ;
%template(SharedPtrSocket) std::shared_ptr<boost::asio::ip::tcp::socket>;
%template(SharedPtrResolver) std::shared_ptr<boost::asio::ip::tcp::resolver>;
%template(SharedPtr) std::shared_ptr<ur_rtde::RobotState>;





%{
//Only needed by C++ Code.
//Is already included by the files which needs it.
//#include "../Linux64/ur_rtde/rtde_export.h"
#include <sstream>
#include <iostream>
#include "../Linux64/ur_rtde/rtde.h"
#include "../Linux64/ur_rtde/dashboard_enums.h"
#include "../Linux64/ur_rtde/dashboard_client.h"
#include "../Linux64/ur_rtde/robot_state.h"
#include "../Linux64/ur_rtde/rtde_control_interface.h"
#include "../Linux64/ur_rtde/rtde_control_script.h"
#include "../Linux64/ur_rtde/rtde_io_interface.h"
#include "../Linux64/ur_rtde/rtde_receive_interface.h"
#include "../Linux64/ur_rtde/rtde_utility.h"
#include "../Linux64/ur_rtde/script_client.h"
%}
/////////////////////////


namespace std
{
  // 27.6.2.1 Template class basic_ostream
  template<typename _CharT, typename _Traits = char_traits<_CharT> >
  class basic_ostream : virtual public basic_ios<_CharT, _Traits>
  {
  public:
    // Types (inherited from basic_ios (27.4.4)):
    typedef _CharT                     		char_type;
    typedef typename _Traits::int_type 		int_type;
    typedef typename _Traits::pos_type 		pos_type;
    typedef typename _Traits::off_type 		off_type;
    typedef _Traits                    		traits_type;
      
    // 27.6.2.2 Constructor/destructor:
    explicit 
    basic_ostream(basic_streambuf<_CharT, _Traits>* __sb);

    virtual 
    ~basic_ostream();
    
   basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& (*__pf)(basic_ostream<_CharT, _Traits>&));

      
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ios<_CharT, _Traits>& (*__pf)(basic_ios<_CharT, _Traits>&));


    basic_ostream<_CharT, _Traits>&
    operator<<(ios_base& (*__pf) (ios_base&));
    
    // 27.6.2.5.2 Arithmetic Inserters

    basic_ostream<_CharT, _Traits>& 
    operator<<(long __n);
    
    basic_ostream<_CharT, _Traits>& 
    operator<<(unsigned long __n);
    
    basic_ostream<_CharT, _Traits>& 
    operator<<(bool __n);
    
    basic_ostream<_CharT, _Traits>& 
    operator<<(short __n);

    basic_ostream<_CharT, _Traits>& 
    operator<<(unsigned short __n);

    basic_ostream<_CharT, _Traits>& 
    operator<<(int __n);

    basic_ostream<_CharT, _Traits>& 
    operator<<(unsigned int __n);

    basic_ostream<_CharT, _Traits>& 
    operator<<(long long __n);

    basic_ostream<_CharT, _Traits>& 
    operator<<(unsigned long long __n);

    basic_ostream<_CharT, _Traits>& 
    operator<<(double __f);

    basic_ostream<_CharT, _Traits>& 
    operator<<(float __f);

    basic_ostream<_CharT, _Traits>& 
    operator<<(long double __f);

    basic_ostream<_CharT, _Traits>& 
    operator<<(const void* __p);

    basic_ostream<_CharT, _Traits>& 
    operator<<(basic_streambuf<_CharT, _Traits>* __sb);

     %extend {
      std::basic_ostream<_CharT, _Traits >& 
	operator<<(const std::basic_string<_CharT,_Traits, std::allocator<_CharT> >& s)
	{
	  *self << s;
	  return *self;
	}
    }

    // Unformatted output:
    basic_ostream<_CharT, _Traits>& 
    put(char_type __c);

    basic_ostream<_CharT, _Traits>& 
    write(const char_type* __s, streamsize __n);

    basic_ostream<_CharT, _Traits>& 
    flush();

    // Seeks:
    pos_type 
    tellp();

    basic_ostream<_CharT, _Traits>& 
    seekp(pos_type);

    basic_ostream<_CharT, _Traits>& 
    seekp(off_type, ios_base::seekdir);
};
 typedef basic_ostream<char> ostream ;
//extern ostream cout;
//extern ostream cerr;
//extern ostream clog;

 }
// namespace std {
 // %template(ostream) basic_ostream<char>;
//  %template(endl) endl<char, std::char_traits<char> >;
//  %template(ends) ends<char, std::char_traits<char> >;
//  %template(flush) flush<char, std::char_traits<char> >;
//  }





//Used that Wrapping of Line 36 ("RTDE_EXPORT explicit RTDE" [...]) of rtde.h ist correctly mapped
#define RTDE_EXPORT


%include "../Linux64/ur_rtde/rtde.h"
%include "../Linux64/ur_rtde/dashboard_enums.h"
%include "../Linux64/ur_rtde/dashboard_client.h"
%include "../Linux64/ur_rtde/robot_state.h"
%include "../Linux64/ur_rtde/rtde_control_interface.h" //Warning 322
%include "../Linux64/ur_rtde/rtde_control_script.h"
%include "../Linux64/ur_rtde/rtde_io_interface.h" //Warning 322
%include "../Linux64/ur_rtde/rtde_receive_interface.h"
%include "../Linux64/ur_rtde/rtde_utility.h"
%include "../Linux64/ur_rtde/script_client.h"


