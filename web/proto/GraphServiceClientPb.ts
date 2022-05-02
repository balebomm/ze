/**
 * @fileoverview gRPC-Web generated client stub for proto
 * @enhanceable
 * @public
 */

// GENERATED CODE -- DO NOT EDIT!


/* eslint-disable */
// @ts-nocheck


import * as grpcWeb from 'grpc-web';

import * as graph_pb from './graph_pb';


export class Graph_ServiceClient {
  client_: grpcWeb.AbstractClientBase;
  hostname_: string;
  credentials_: null | { [index: string]: string; };
  options_: null | { [index: string]: any; };

  constructor (hostname: string,
               credentials?: null | { [index: string]: string; },
               options?: null | { [index: string]: any; }) {
    if (!options) options = {};
    if (!credentials) credentials = {};
    options['format'] = 'binary';

    this.client_ = new grpcWeb.GrpcWebClientBase(options);
    this.hostname_ = hostname;
    this.credentials_ = credentials;
    this.options_ = options;
  }

  methodDescriptorGetRoute = new grpcWeb.MethodDescriptor(
    '/proto.Graph_Service/GetRoute',
    grpcWeb.MethodType.UNARY,
    graph_pb.Graph_RouteRequest,
    graph_pb.Graph_RouteResponse,
    (request: graph_pb.Graph_RouteRequest) => {
      return request.serializeBinary();
    },
    graph_pb.Graph_RouteResponse.deserializeBinary
  );

  getRoute(
    request: graph_pb.Graph_RouteRequest,
    metadata: grpcWeb.Metadata | null): Promise<graph_pb.Graph_RouteResponse>;

  getRoute(
    request: graph_pb.Graph_RouteRequest,
    metadata: grpcWeb.Metadata | null,
    callback: (err: grpcWeb.RpcError,
               response: graph_pb.Graph_RouteResponse) => void): grpcWeb.ClientReadableStream<graph_pb.Graph_RouteResponse>;

  getRoute(
    request: graph_pb.Graph_RouteRequest,
    metadata: grpcWeb.Metadata | null,
    callback?: (err: grpcWeb.RpcError,
               response: graph_pb.Graph_RouteResponse) => void) {
    if (callback !== undefined) {
      return this.client_.rpcCall(
        this.hostname_ +
          '/proto.Graph_Service/GetRoute',
        request,
        metadata || {},
        this.methodDescriptorGetRoute,
        callback);
    }
    return this.client_.unaryCall(
    this.hostname_ +
      '/proto.Graph_Service/GetRoute',
    request,
    metadata || {},
    this.methodDescriptorGetRoute);
  }

  methodDescriptorSetConfig = new grpcWeb.MethodDescriptor(
    '/proto.Graph_Service/SetConfig',
    grpcWeb.MethodType.UNARY,
    graph_pb.Graph_ConfigRequest,
    graph_pb.Graph_EmptyResponse,
    (request: graph_pb.Graph_ConfigRequest) => {
      return request.serializeBinary();
    },
    graph_pb.Graph_EmptyResponse.deserializeBinary
  );

  setConfig(
    request: graph_pb.Graph_ConfigRequest,
    metadata: grpcWeb.Metadata | null): Promise<graph_pb.Graph_EmptyResponse>;

  setConfig(
    request: graph_pb.Graph_ConfigRequest,
    metadata: grpcWeb.Metadata | null,
    callback: (err: grpcWeb.RpcError,
               response: graph_pb.Graph_EmptyResponse) => void): grpcWeb.ClientReadableStream<graph_pb.Graph_EmptyResponse>;

  setConfig(
    request: graph_pb.Graph_ConfigRequest,
    metadata: grpcWeb.Metadata | null,
    callback?: (err: grpcWeb.RpcError,
               response: graph_pb.Graph_EmptyResponse) => void) {
    if (callback !== undefined) {
      return this.client_.rpcCall(
        this.hostname_ +
          '/proto.Graph_Service/SetConfig',
        request,
        metadata || {},
        this.methodDescriptorSetConfig,
        callback);
    }
    return this.client_.unaryCall(
    this.hostname_ +
      '/proto.Graph_Service/SetConfig',
    request,
    metadata || {},
    this.methodDescriptorSetConfig);
  }

}

