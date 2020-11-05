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


/////////////////////////////////


%{
//Only needed by C++ Code.
//Is already included by the files which needs it.
//#include "../Linux64/ur_rtde/rtde_export.h"

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


/////////////////////////////////


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

