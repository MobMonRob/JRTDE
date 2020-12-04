%module RTDE_MODULE


%feature("nspace");

SWIG_JAVABODY_PROXY(public, public, SWIGTYPE)
SWIG_JAVABODY_TYPEWRAPPER(public, public, public, SWIGTYPE)
SWIG_JAVABODY_METHODS(public, public, SWIGTYPE)

%warnfilter(322) MAJOR_VERSION;
%warnfilter(322) CB3_MAJOR_VERSION;

%include <std_shared_ptr.i>
%include <boost_shared_ptr.i>
//%include "std_shared_ptr.i";
%include "std_string.i";
%include "arrays_java.i";
//%include "std_vector.i"
%include "stdint.i";
//%include "typemaps/fragments.swg"
//%include "std_iostream.i";
%include "std_vector.i";



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
//#include "../Linux64/ur_client_library/rtde_export.h"
#include <sstream>
#include <iostream>
#include "../Linux64/ur_client_library/rtde/rtde_client.h"
#include "../Linux64/ur_client_library/rtde/control_package_pause.h"
#include "../Linux64/ur_client_library/rtde/control_package_setup_inputs.h"
#include "../Linux64/ur_client_library/rtde/control_package_setup_outputs.h"
#include "../Linux64/ur_client_library/rtde/control_package_start.h"
#include "../Linux64/ur_client_library/rtde/data_package.h"
#include "../Linux64/ur_client_library/rtde/get_urcontrol_version.h"
#include "../Linux64/ur_client_library/rtde/package_header.h"
#include "../Linux64/ur_client_library/rtde/request_protocol_version.h"
#include "../Linux64/ur_client_library/rtde/rtde_package.h"
#include "../Linux64/ur_client_library/rtde/rtde_parser.h"
#include "../Linux64/ur_client_library/rtde/rtde_writer.h"
#include "../Linux64/ur_client_library/rtde/text_message.h"
%}
/////////////////////////
%{
#include <vector>
#include <stdexcept>
%}

%include <stdint.i>
%include <std_except.i>
/*
%include "std_vector.i"
//namespace std {
%template(VectorDouble) vector::<double>;
%template(VectorInt) vector::<int>;
%template(VectorVectorDouble) vector::<std::vector<double>>;
%template(VectorString) vector::<std::string>;
%template(VectorChar) vector::<char>;

%template(SharedPtrService) shared_ptr<boost::asio::io_service> ;
%template(SharedPtrSocket) shared_ptr<boost::asio::ip::tcp::socket>;
%template(SharedPtrResolver) shared_ptr<boost::asio::ip::tcp::resolver>;
%template(SharedPtr) shared_ptr<ur_rtde::RobotState>;
//}

*/


// neu
%rename (RobotState) ur_rtde::RobotState;

//Used that Wrapping of Line 36 ("RTDE_EXPORT explicit RTDE" [...]) of rtde.h is correctly mapped
#define RTDE_EXPORT


#include "../Linux64/ur_client_library/rtde/rtde_client.h"
#include "../Linux64/ur_client_library/rtde/control_package_pause.h"
#include "../Linux64/ur_client_library/rtde/control_package_setup_inputs.h"
#include "../Linux64/ur_client_library/rtde/control_package_setup_outputs.h"
#include "../Linux64/ur_client_library/rtde/control_package_start.h"
#include "../Linux64/ur_client_library/rtde/data_package.h"
#include "../Linux64/ur_client_library/rtde/get_urcontrol_version.h"
#include "../Linux64/ur_client_library/rtde/package_header.h"
#include "../Linux64/ur_client_library/rtde/request_protocol_version.h"
#include "../Linux64/ur_client_library/rtde/rtde_package.h"
#include "../Linux64/ur_client_library/rtde/rtde_parser.h"
#include "../Linux64/ur_client_library/rtde/rtde_writer.h"
#include "../Linux64/ur_client_library/rtde/text_message.h"
