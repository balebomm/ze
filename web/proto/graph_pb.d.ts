import * as jspb from 'google-protobuf'



export class Graph_Location extends jspb.Message {
  getType(): string;
  setType(value: string): Graph_Location;

  getCoordinatesList(): Array<number>;
  setCoordinatesList(value: Array<number>): Graph_Location;
  clearCoordinatesList(): Graph_Location;
  addCoordinates(value: number, index?: number): Graph_Location;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): Graph_Location.AsObject;
  static toObject(includeInstance: boolean, msg: Graph_Location): Graph_Location.AsObject;
  static serializeBinaryToWriter(message: Graph_Location, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): Graph_Location;
  static deserializeBinaryFromReader(message: Graph_Location, reader: jspb.BinaryReader): Graph_Location;
}

export namespace Graph_Location {
  export type AsObject = {
    type: string,
    coordinatesList: Array<number>,
  }
}

export class Graph_Point extends jspb.Message {
  getNodeId(): number;
  setNodeId(value: number): Graph_Point;

  getLocation(): Graph_Location | undefined;
  setLocation(value?: Graph_Location): Graph_Point;
  hasLocation(): boolean;
  clearLocation(): Graph_Point;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): Graph_Point.AsObject;
  static toObject(includeInstance: boolean, msg: Graph_Point): Graph_Point.AsObject;
  static serializeBinaryToWriter(message: Graph_Point, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): Graph_Point;
  static deserializeBinaryFromReader(message: Graph_Point, reader: jspb.BinaryReader): Graph_Point;
}

export namespace Graph_Point {
  export type AsObject = {
    nodeId: number,
    location?: Graph_Location.AsObject,
  }
}

export class Graph_RouteRequest extends jspb.Message {
  getFrom(): Graph_Point | undefined;
  setFrom(value?: Graph_Point): Graph_RouteRequest;
  hasFrom(): boolean;
  clearFrom(): Graph_RouteRequest;

  getTo(): Graph_Point | undefined;
  setTo(value?: Graph_Point): Graph_RouteRequest;
  hasTo(): boolean;
  clearTo(): Graph_RouteRequest;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): Graph_RouteRequest.AsObject;
  static toObject(includeInstance: boolean, msg: Graph_RouteRequest): Graph_RouteRequest.AsObject;
  static serializeBinaryToWriter(message: Graph_RouteRequest, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): Graph_RouteRequest;
  static deserializeBinaryFromReader(message: Graph_RouteRequest, reader: jspb.BinaryReader): Graph_RouteRequest;
}

export namespace Graph_RouteRequest {
  export type AsObject = {
    from?: Graph_Point.AsObject,
    to?: Graph_Point.AsObject,
  }
}

export class Graph_RouteResponse extends jspb.Message {
  getTotalDistance(): number;
  setTotalDistance(value: number): Graph_RouteResponse;

  getShortestRoutesList(): Array<Graph_Location>;
  setShortestRoutesList(value: Array<Graph_Location>): Graph_RouteResponse;
  clearShortestRoutesList(): Graph_RouteResponse;
  addShortestRoutes(value?: Graph_Location, index?: number): Graph_Location;

  getTraverseFowardRoutesList(): Array<Graph_Location>;
  setTraverseFowardRoutesList(value: Array<Graph_Location>): Graph_RouteResponse;
  clearTraverseFowardRoutesList(): Graph_RouteResponse;
  addTraverseFowardRoutes(value?: Graph_Location, index?: number): Graph_Location;

  getTraverseBackwardRoutesList(): Array<Graph_Location>;
  setTraverseBackwardRoutesList(value: Array<Graph_Location>): Graph_RouteResponse;
  clearTraverseBackwardRoutesList(): Graph_RouteResponse;
  addTraverseBackwardRoutes(value?: Graph_Location, index?: number): Graph_Location;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): Graph_RouteResponse.AsObject;
  static toObject(includeInstance: boolean, msg: Graph_RouteResponse): Graph_RouteResponse.AsObject;
  static serializeBinaryToWriter(message: Graph_RouteResponse, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): Graph_RouteResponse;
  static deserializeBinaryFromReader(message: Graph_RouteResponse, reader: jspb.BinaryReader): Graph_RouteResponse;
}

export namespace Graph_RouteResponse {
  export type AsObject = {
    totalDistance: number,
    shortestRoutesList: Array<Graph_Location.AsObject>,
    traverseFowardRoutesList: Array<Graph_Location.AsObject>,
    traverseBackwardRoutesList: Array<Graph_Location.AsObject>,
  }
}

export class Graph_ConfigRequest extends jspb.Message {
  getAlgorithmType(): Graph_ConfigRequest.AlgorithmType;
  setAlgorithmType(value: Graph_ConfigRequest.AlgorithmType): Graph_ConfigRequest;

  getTotalDistance(): boolean;
  setTotalDistance(value: boolean): Graph_ConfigRequest;
  hasTotalDistance(): boolean;
  clearTotalDistance(): Graph_ConfigRequest;

  getShortestRoutes(): boolean;
  setShortestRoutes(value: boolean): Graph_ConfigRequest;
  hasShortestRoutes(): boolean;
  clearShortestRoutes(): Graph_ConfigRequest;

  getTraverseForwardRoutes(): boolean;
  setTraverseForwardRoutes(value: boolean): Graph_ConfigRequest;
  hasTraverseForwardRoutes(): boolean;
  clearTraverseForwardRoutes(): Graph_ConfigRequest;

  getTraverseBackwardRoutes(): boolean;
  setTraverseBackwardRoutes(value: boolean): Graph_ConfigRequest;
  hasTraverseBackwardRoutes(): boolean;
  clearTraverseBackwardRoutes(): Graph_ConfigRequest;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): Graph_ConfigRequest.AsObject;
  static toObject(includeInstance: boolean, msg: Graph_ConfigRequest): Graph_ConfigRequest.AsObject;
  static serializeBinaryToWriter(message: Graph_ConfigRequest, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): Graph_ConfigRequest;
  static deserializeBinaryFromReader(message: Graph_ConfigRequest, reader: jspb.BinaryReader): Graph_ConfigRequest;
}

export namespace Graph_ConfigRequest {
  export type AsObject = {
    algorithmType: Graph_ConfigRequest.AlgorithmType,
    totalDistance?: boolean,
    shortestRoutes?: boolean,
    traverseForwardRoutes?: boolean,
    traverseBackwardRoutes?: boolean,
  }

  export enum AlgorithmType { 
    DIJKSTRA = 0,
    BIDIRECTIONALDIJKSTRA = 1,
    ASTAR = 2,
    BIDIRECTIONALASTAR = 3,
    BIDIRECTIONALASTARLANDMARK = 4,
  }

  export enum TotalDistanceCase { 
    _TOTAL_DISTANCE_NOT_SET = 0,
    TOTAL_DISTANCE = 2,
  }

  export enum ShortestRoutesCase { 
    _SHORTEST_ROUTES_NOT_SET = 0,
    SHORTEST_ROUTES = 3,
  }

  export enum TraverseForwardRoutesCase { 
    _TRAVERSE_FORWARD_ROUTES_NOT_SET = 0,
    TRAVERSE_FORWARD_ROUTES = 4,
  }

  export enum TraverseBackwardRoutesCase { 
    _TRAVERSE_BACKWARD_ROUTES_NOT_SET = 0,
    TRAVERSE_BACKWARD_ROUTES = 5,
  }
}

export class Graph_EmptyResponse extends jspb.Message {
  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): Graph_EmptyResponse.AsObject;
  static toObject(includeInstance: boolean, msg: Graph_EmptyResponse): Graph_EmptyResponse.AsObject;
  static serializeBinaryToWriter(message: Graph_EmptyResponse, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): Graph_EmptyResponse;
  static deserializeBinaryFromReader(message: Graph_EmptyResponse, reader: jspb.BinaryReader): Graph_EmptyResponse;
}

export namespace Graph_EmptyResponse {
  export type AsObject = {
  }
}

