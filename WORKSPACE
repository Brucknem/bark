workspace(name = "bark_project")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")


# ---- BARK Internal Dependencies ----------------
load("@bark_project//tools:deps.bzl", "bark_dependencies")
bark_dependencies()


load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()
# -------------------------------------------------



# ------ Planner UCT ------------------------------
git_repository(
  name = "planner_uct",
  commit="1338b8ed3906d9564f4ec26c0c122ea211d1df81",
  remote = "https://github.com/bark-simulator/planner-mcts"
)
load("@planner_uct//util:deps.bzl", "planner_uct_rules_dependencies")
planner_uct_rules_dependencies()
# --------------------------------------------------



# ------ Planner BARK-ML ---------------------------
git_repository(
  name = "bark_ml",
  branch="master",
  remote = "https://github.com/bark-simulator/bark-ml"
)
# --------------------------------------------------



# -------- Benchmark Database -----------------------
git_repository(
  name = "benchmark_database",
  commit="feca819b1ad03898a13527ecacfa3881c9786dd1",
  remote = "https://github.com/bark-simulator/benchmark-database"
)

load("@benchmark_database//util:deps.bzl", "benchmark_database_dependencies")
load("@benchmark_database//load:load.bzl", "benchmark_database_release")
benchmark_database_dependencies()
benchmark_database_release()
# --------------------------------------------------


#git_repository(
#  name = "interaction_dataset_fortiss_internal",
#  branch = "master",
#  remote = "https://git.fortiss.org/autosim/interaction_dataset"
#)

