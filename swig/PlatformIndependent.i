%module RTDE_MODULE
//%include "std_unordered_map.i"
%include "std_shared_ptr.i";
%include "std_string.i";
%include "arrays_java.i";
%include "std_vector.i"
//namespace std
//%include "std/std_iostream.i";
//%include "std_pair.i"
%include "stdint.i";



#include <iostream>
#include "../Linux64/urtde/rtde_export.h"
#define RTDE_EXPORT

//#define SWIG_SHARED_PTR_NAMESPACE std

#include "../Linux64/urtde/rtde_control_interface_doc.h"
#include "../Linux64/urtde/dashboard_enums.h"
#include "../Linux64/urtde/dashboard_client.h"
#include "../Linux64/urtde/robot_state.h"
#include "../Linux64/urtde/rtde_control_interface.h"
#include "../Linux64/urtde/rtde_control_script.h"

#include "../Linux64/urtde/rtde_io_interface_doc.h"
#include "../Linux64/urtde/rtde_io_interface.h"
#include "../Linux64/urtde/rtde_receive_interface_doc.h"
#include "../Linux64/urtde/rtde_receive_interface.h"
#include "../Linux64/urtde/rtde_utility.h"
#include "../Linux64/urtde/rtde.h"
#include "../Linux64/urtde/script_client.h"



%include <boost_shared_ptr.i>;
%template(VectorDouble) std::vector<double>;
%template(VectorInt) std::vector<int>;
%template(VectorVectorDouble) std::vector<std::vector<double>>;
%template(VectorString) std::vector<std::string>;
%template(VectorChar) std::vector<char>;
//%template(SharedPtrService) std::shared_ptr<boost::asio::io_service> ;
//%template(SharedPtrSocket) std::shared_ptr<boost::asio::ip::tcp::socket>;
//%template(SharedPtrResolver)std::shared_ptr<boost::asio::ip::tcp::resolver>;
// %template(ostringstream)std::ostringstream ;

////////////////////////////////////////

// hier ist std::unit32_t wurde als unsigned integer gewrappt durch stdint.i

//%template(Tuple) std::tuple<std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t>;
//%template(Tuple) std::tuple<unsigned int, unsigned int, unsigned int, unsigned int>;
%template(SharedPtr) std::shared_ptr<ur_rtde::RobotState>;

///////////////////////////////




/////////////////////////////////

%include "../Linux64/urtde/rtde_export.h"

%include "../Linux64/urtde/rtde_control_interface_doc.h"
%include "../Linux64/urtde/dashboard_enums.h"
%include "../Linux64/urtde/dashboard_client.h"
%include "../Linux64/urtde/robot_state.h"
%include "../Linux64/urtde/rtde_control_interface.h"
%include "../Linux64/urtde/rtde_control_script.h"

%include "../Linux64/urtde/rtde_io_interface_doc.h"
%include "../Linux64/urtde/rtde_io_interface.h"
%include "../Linux64/urtde/rtde_receive_interface_doc.h"
%include "../Linux64/urtde/rtde_receive_interface.h"
%include "../Linux64/urtde/rtde_utility.h"
%include "../Linux64/urtde/rtde.h"
%include "../Linux64/urtde/script_client.h"

