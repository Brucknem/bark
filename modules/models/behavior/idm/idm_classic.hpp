// Copyright (c) 2020 Julian Bernhard, Klemens Esterle, Patrick Hart and
// Tobias Kessler
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#ifndef MODULES_MODELS_BEHAVIOR_IDM_IDM_CLASSIC_HPP_
#define MODULES_MODELS_BEHAVIOR_IDM_IDM_CLASSIC_HPP_

#include <memory>
#include <tuple>

#include "modules/commons/transformation/frenet.hpp"
#include "modules/world/world.hpp"
#include "modules/models/behavior/idm/base_idm.hpp"

namespace modules {
namespace models {
namespace behavior {

using modules::world::map::LaneCorridor;
using modules::world::map::LaneCorridorPtr;

// IDM that interpolates the vehicles using the center-line
// of a LaneCorridor
class BehaviorIDMClassic : public BaseIDM {
 public:
  explicit BehaviorIDMClassic(const commons::ParamsPtr& params) :
    BaseIDM(params) {}

  virtual ~BehaviorIDMClassic() {}

  std::tuple<Trajectory, Action> GenerateTrajectory(
    const world::ObservedWorld& observed_world,
    const LaneCorridorPtr& lane_corr,
    const IDMRelativeValues& rel_values,
    double delta_time) const;

  virtual std::shared_ptr<BehaviorModel> Clone() const;
};

inline std::shared_ptr<BehaviorModel> BehaviorIDMClassic::Clone() const {
  std::shared_ptr<BehaviorIDMClassic> model_ptr =
      std::make_shared<BehaviorIDMClassic>(*this);
  return model_ptr;
}

}  // namespace behavior
}  // namespace models
}  // namespace modules

#endif  // MODULES_MODELS_BEHAVIOR_IDM_IDM_CLASSIC_HPP_
