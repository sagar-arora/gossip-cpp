load("@rules_proto_grpc//:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_compile")

proto_library(
    name = "gossip",
    srcs = ["gossip.proto"],
    visibility = ["//visibility:public"],
)

cpp_proto_compile(
    name = "gossip",
    protos = [":gossip"],
)