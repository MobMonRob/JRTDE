namespace ur_rtde {
class ScriptClient {
};
class RTDE{
class RobotCommand;
  
};
class RTDEReceiveInterface {
};
class RTDEUtility {
};
class RTDEIOInterface {
};
class RTDEControlInterface {
};
class RobotState  {
};
class DashboardClient  {
};

class RobotMode {
};
class PolyScopeVersion  {
};
class parseRobotMode  {
};
class SafetyStatus  {
};

class SafetyMode {
};
class parseSafetyMode {
};


class ProgramState {
};
namespace ur_rtde
{
class RobotState;
}

namespace ur_rtde
{
namespace details
{
// convenience alias for callback functions used within RTDE::recieveData()
using cb_fun = std::function<void(std::shared_ptr<RobotState>, std::vector<char> &, uint32_t &)>;
// convenience alias for the callback map of string ids and callback funtion objects
using cb_map = std::unordered_map<std::string, details::cb_fun>;
}  // namespace details


}
}
