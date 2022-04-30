/**
 * @fileoverview gRPC-Web generated client stub for proto
 * @enhanceable
 * @public
 */

// GENERATED CODE -- DO NOT EDIT!


/* eslint-disable */
// @ts-nocheck



const grpc = {};
grpc.web = require('grpc-web');

const proto = {};
proto.proto = require('./graph_pb.js');

/**
 * @param {string} hostname
 * @param {?Object} credentials
 * @param {?grpc.web.ClientOptions} options
 * @constructor
 * @struct
 * @final
 */
proto.proto.Graph_Client =
    function(hostname, credentials, options) {
  if (!options) options = {};
  options.format = 'text';

  /**
   * @private @const {!grpc.web.GrpcWebClientBase} The client
   */
  this.client_ = new grpc.web.GrpcWebClientBase(options);

  /**
   * @private @const {string} The hostname
   */
  this.hostname_ = hostname;

};


/**
 * @param {string} hostname
 * @param {?Object} credentials
 * @param {?grpc.web.ClientOptions} options
 * @constructor
 * @struct
 * @final
 */
proto.proto.Graph_PromiseClient =
    function(hostname, credentials, options) {
  if (!options) options = {};
  options.format = 'text';

  /**
   * @private @const {!grpc.web.GrpcWebClientBase} The client
   */
  this.client_ = new grpc.web.GrpcWebClientBase(options);

  /**
   * @private @const {string} The hostname
   */
  this.hostname_ = hostname;

};


/**
 * @const
 * @type {!grpc.web.MethodDescriptor<
 *   !proto.proto.Graph_RouteRequest,
 *   !proto.proto.Graph_RouteResponse>}
 */
const methodDescriptor_Graph__GetRoute = new grpc.web.MethodDescriptor(
  '/proto.Graph_/GetRoute',
  grpc.web.MethodType.UNARY,
  proto.proto.Graph_RouteRequest,
  proto.proto.Graph_RouteResponse,
  /**
   * @param {!proto.proto.Graph_RouteRequest} request
   * @return {!Uint8Array}
   */
  function(request) {
    return request.serializeBinary();
  },
  proto.proto.Graph_RouteResponse.deserializeBinary
);


/**
 * @param {!proto.proto.Graph_RouteRequest} request The
 *     request proto
 * @param {?Object<string, string>} metadata User defined
 *     call metadata
 * @param {function(?grpc.web.RpcError, ?proto.proto.Graph_RouteResponse)}
 *     callback The callback function(error, response)
 * @return {!grpc.web.ClientReadableStream<!proto.proto.Graph_RouteResponse>|undefined}
 *     The XHR Node Readable Stream
 */
proto.proto.Graph_Client.prototype.getRoute =
    function(request, metadata, callback) {
  return this.client_.rpcCall(this.hostname_ +
      '/proto.Graph_/GetRoute',
      request,
      metadata || {},
      methodDescriptor_Graph__GetRoute,
      callback);
};


/**
 * @param {!proto.proto.Graph_RouteRequest} request The
 *     request proto
 * @param {?Object<string, string>=} metadata User defined
 *     call metadata
 * @return {!Promise<!proto.proto.Graph_RouteResponse>}
 *     Promise that resolves to the response
 */
proto.proto.Graph_PromiseClient.prototype.getRoute =
    function(request, metadata) {
  return this.client_.unaryCall(this.hostname_ +
      '/proto.Graph_/GetRoute',
      request,
      metadata || {},
      methodDescriptor_Graph__GetRoute);
};


module.exports = proto.proto;

