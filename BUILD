cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [":ab_test"]
)

cc_library(
    name = "ab_test",
    srcs = ["ab_test.cc"],
    hdrs = ["ab_test.h"],
    deps = [":stats"]
)

cc_library(
    name = "stats",
    srcs = ["stats.cc"],
    hdrs = ["stats.h"],
    deps = [
        "@boost//:math"
    ]
)
