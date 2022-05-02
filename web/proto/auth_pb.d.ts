import * as jspb from 'google-protobuf'



export class Auth_LoginRequest extends jspb.Message {
  getUsername(): string;
  setUsername(value: string): Auth_LoginRequest;

  getPassword(): string;
  setPassword(value: string): Auth_LoginRequest;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): Auth_LoginRequest.AsObject;
  static toObject(includeInstance: boolean, msg: Auth_LoginRequest): Auth_LoginRequest.AsObject;
  static serializeBinaryToWriter(message: Auth_LoginRequest, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): Auth_LoginRequest;
  static deserializeBinaryFromReader(message: Auth_LoginRequest, reader: jspb.BinaryReader): Auth_LoginRequest;
}

export namespace Auth_LoginRequest {
  export type AsObject = {
    username: string,
    password: string,
  }
}

export class Auth_LoginResponse extends jspb.Message {
  getSession(): string;
  setSession(value: string): Auth_LoginResponse;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): Auth_LoginResponse.AsObject;
  static toObject(includeInstance: boolean, msg: Auth_LoginResponse): Auth_LoginResponse.AsObject;
  static serializeBinaryToWriter(message: Auth_LoginResponse, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): Auth_LoginResponse;
  static deserializeBinaryFromReader(message: Auth_LoginResponse, reader: jspb.BinaryReader): Auth_LoginResponse;
}

export namespace Auth_LoginResponse {
  export type AsObject = {
    session: string,
  }
}

