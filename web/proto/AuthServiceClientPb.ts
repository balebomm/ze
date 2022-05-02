/**
 * @fileoverview gRPC-Web generated client stub for proto
 * @enhanceable
 * @public
 */

// GENERATED CODE -- DO NOT EDIT!


/* eslint-disable */
// @ts-nocheck


import * as grpcWeb from 'grpc-web';

import * as auth_pb from './auth_pb';


export class Auth_ServiceClient {
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

  methodDescriptorLogin = new grpcWeb.MethodDescriptor(
    '/proto.Auth_Service/Login',
    grpcWeb.MethodType.UNARY,
    auth_pb.Auth_LoginRequest,
    auth_pb.Auth_LoginResponse,
    (request: auth_pb.Auth_LoginRequest) => {
      return request.serializeBinary();
    },
    auth_pb.Auth_LoginResponse.deserializeBinary
  );

  login(
    request: auth_pb.Auth_LoginRequest,
    metadata: grpcWeb.Metadata | null): Promise<auth_pb.Auth_LoginResponse>;

  login(
    request: auth_pb.Auth_LoginRequest,
    metadata: grpcWeb.Metadata | null,
    callback: (err: grpcWeb.RpcError,
               response: auth_pb.Auth_LoginResponse) => void): grpcWeb.ClientReadableStream<auth_pb.Auth_LoginResponse>;

  login(
    request: auth_pb.Auth_LoginRequest,
    metadata: grpcWeb.Metadata | null,
    callback?: (err: grpcWeb.RpcError,
               response: auth_pb.Auth_LoginResponse) => void) {
    if (callback !== undefined) {
      return this.client_.rpcCall(
        this.hostname_ +
          '/proto.Auth_Service/Login',
        request,
        metadata || {},
        this.methodDescriptorLogin,
        callback);
    }
    return this.client_.unaryCall(
    this.hostname_ +
      '/proto.Auth_Service/Login',
    request,
    metadata || {},
    this.methodDescriptorLogin);
  }

}

