// Copyright (c) 2020 Julian Bernhard, Klemens Esterle, Patrick Hart and
// Tobias Kessler
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.


#include <iostream>
#include "modules/models/execution/interpolation/interpolate.hpp"


namespace modules {
namespace models {
namespace execution {

dynamic::Trajectory ExecutionModelInterpolate::Execute(
    const float& new_world_time,
    const dynamic::Trajectory& trajectory,
    const dynamic::DynamicModelPtr dynamic_model,
    const dynamic::State current_state) {

  // TODO(@all) fix interpolation model
  Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> traj = trajectory;
  SetLastTrajectory(traj);
  return traj;
}

}  // namespace execution
}  // namespace models
}  // namespace modules
