%module RTDE_MODULE


%javaconst(1);
//%include <swigarch.i>

//%include "std_unordered_map.i"
%include "std_shared_ptr.i";
%include "std_string.i";
%include "arrays_java.i";
%include "std_vector.i"
%include <boost_shared_ptr.i>
//%shared_ptr(IntValue)
//%include <boost/asio.hpp>;
%include "java.swg"

//%include "std/std_iostream.i";
//%include "std_pair.i"
%include "stdint.i";

%include "java/typemaps.i" 
//%include "cpointer.i"
//%include "stl.i" 
%apply uint32_t&  INOUT { uint32_t&  }; 
%include rtde.i
%ignore __doc_ur_rtde_RTDEReceiveInterface;




#include <iostream>
#include "../Linux64/ur_rtde/rtde_export.h"
#define RTDE_EXPORT
#include <memory>;






//typedef unsigned int		uint32_t;

//#include "../Linux64/ur_rtde/rtde_control_interface_doc.h" //not needed, causes erros
#include "../Linux64/ur_rtde/dashboard_enums.h"
#include "../Linux64/ur_rtde/dashboard_client.h"
#include "../Linux64/ur_rtde/robot_state.h"
#include "../Linux64/ur_rtde/rtde_control_interface.h"
#include "../Linux64/ur_rtde/rtde_control_script.h"

#include "../Linux64/ur_rtde/rtde_io_interface_doc.h"
#include "../Linux64/ur_rtde/rtde_io_interface.h"
//#include "../Linux64/ur_rtde/rtde_receive_interface_doc.h" //not needed, causes erros
#include "../Linux64/ur_rtde/rtde_receive_interface.h"
#include "../Linux64/ur_rtde/rtde_utility.h"
#include "../Linux64/ur_rtde/rtde.h"
#include "../Linux64/ur_rtde/script_client.h"

%immutable ur_rtde;
%include <boost_shared_ptr.i>;
%template(VectorDouble) std::vector<double>;
%template(VectorInt) std::vector<int>;
%template(VectorVectorDouble) std::vector<std::vector<double>>;
%template(VectorString) std::vector<std::string>;
%template(VectorChar) std::vector<char>;
%template(SharedPtrService) std::shared_ptr<boost::asio::io_service> ;
%template(SharedPtrSocket) std::shared_ptr<boost::asio::ip::tcp::socket>;
%template(SharedPtrResolver)std::shared_ptr<boost::asio::ip::tcp::resolver>;
//%template(ostringstream)std::ostringstream ;

////////////////////////////////////////

// hier ist std::uint32_t wurde als unsigned integer gewrappt durch stdint.i

//%template(Tuple) std::tuple<std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t>;
//%template(CppTuple) std::tuple<unsigned int, unsigned int, unsigned int, unsigned int>;
%template(SharedPtr) std::shared_ptr<ur_rtde::RobotState>;

///////////////////////////////

//%ignore ur_rtde::RTDEUtility::hexDump;


/////////////////////////////////
%include "../Linux64/ur_rtde/rtde_export.h"

//%include "../Linux64/ur_rtde/rtde_control_interface_doc.h" //not needed, causes erros
%include "../Linux64/ur_rtde/dashboard_enums.h"
%include "../Linux64/ur_rtde/dashboard_client.h"
%include "../Linux64/ur_rtde/robot_state.h"
%include "../Linux64/ur_rtde/rtde_control_interface.h"
%include "../Linux64/ur_rtde/rtde_control_script.h"

//%include "../Linux64/ur_rtde/rtde_io_interface_doc.h" //not needed, causes erros
%include "../Linux64/ur_rtde/rtde_io_interface.h"
//%include "../Linux64/ur_rtde/rtde_receive_interface_doc.h" //not needed, causes erros
%include "../Linux64/ur_rtde/rtde_receive_interface.h"
%include "../Linux64/ur_rtde/rtde_utility.h"
%include "../Linux64/ur_rtde/rtde.h"
%include "../Linux64/ur_rtde/script_client.h"

using namespace rtde;
