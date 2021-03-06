// Copyright (c) 2020 fortiss GmbH
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "bark/world/evaluation/ltl/evaluator_zip_merge_chn.hpp"

#include "bark/world/evaluation/ltl/label_functions/agent_at_lane_end_label_function.hpp"
#include "bark/world/evaluation/ltl/label_functions/agent_beyond_point_label_function.hpp"
#include "bark/world/evaluation/ltl/label_functions/agent_near_label_function.hpp"
#include "bark/world/evaluation/ltl/label_functions/behind_of_label_function.hpp"
#include "bark/world/evaluation/ltl/label_functions/ego_beyond_point_label_function.hpp"
#include "bark/world/evaluation/ltl/label_functions/left_of_label_function.hpp"
#include "bark/world/evaluation/ltl/label_functions/preceding_agent_label_function.hpp"

namespace bark {
namespace world {
namespace evaluation {

/// Allow other vehicles on ending lanes to merge (zipper merge)
/// This evaluator is parameterized for the DR_CHN_Merging_ZS scenario of the
/// INTERACTION dataset
const char EvaluatorZipMergeChn::formula_[] =
    "G (((left#1 & i_behind#1 & near#1 & near_lane_end#1) & "
    "precedes#0 & !ego_merged & (precedes#0 | merged#0) U "
    "ego_merged) -> G(ego_merged & merged#0 -> !precedes#0))";

const LabelFunctions EvaluatorZipMergeChn::labels_ = {
    LabelFunctionPtr(
        new AgentBeyondPointLabelFunction("merged", Point2d(1108.0, 943.0))),
    LabelFunctionPtr(
        new EgoBeyondPointLabelFunction("ego_merged", Point2d(1108.0, 943.0))),
    LabelFunctionPtr(new PrecedingAgentLabelFunction("precedes")),
    LabelFunctionPtr(new LeftOfLabelFunction("left")),
    LabelFunctionPtr(new BehindOfLabelFunction("behind")),
    LabelFunctionPtr(new AgentNearLabelFunction("near", 6.0)),
    LabelFunctionPtr(new AgentAtLaneEndLabelFunction("near_lane_end", 20.0))};

}  // namespace evaluation
}  // namespace world
}  // namespace bark
