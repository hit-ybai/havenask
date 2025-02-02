// automatically generated by the FlatBuffers compiler, do not modify

package com.taobao.search.iquan.client.common.fb;

import java.nio.*;
import java.lang.*;
import java.util.*;
import com.google.flatbuffers.*;

@SuppressWarnings("unused")
public final class IquanFbPlanOp extends Table {
  public static IquanFbPlanOp getRootAsIquanFbPlanOp(ByteBuffer _bb) { return getRootAsIquanFbPlanOp(_bb, new IquanFbPlanOp()); }
  public static IquanFbPlanOp getRootAsIquanFbPlanOp(ByteBuffer _bb, IquanFbPlanOp obj) { _bb.order(ByteOrder.LITTLE_ENDIAN); return (obj.__assign(_bb.getInt(_bb.position()) + _bb.position(), _bb)); }
  public void __init(int _i, ByteBuffer _bb) { bb_pos = _i; bb = _bb; }
  public IquanFbPlanOp __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public long id() { int o = __offset(4); return o != 0 ? bb.getLong(o + bb_pos) : 0L; }
  public String opName() { int o = __offset(6); return o != 0 ? __string(o + bb_pos) : null; }
  public ByteBuffer opNameAsByteBuffer() { return __vector_as_bytebuffer(6, 1); }
  public ByteBuffer opNameInByteBuffer(ByteBuffer _bb) { return __vector_in_bytebuffer(_bb, 6, 1); }
  public IquanFbMap inputs() { return inputs(new IquanFbMap()); }
  public IquanFbMap inputs(IquanFbMap obj) { int o = __offset(8); return o != 0 ? obj.__assign(__indirect(o + bb_pos), bb) : null; }
  public IquanFbMap jsonAttrs() { return jsonAttrs(new IquanFbMap()); }
  public IquanFbMap jsonAttrs(IquanFbMap obj) { int o = __offset(10); return o != 0 ? obj.__assign(__indirect(o + bb_pos), bb) : null; }

  public static int createIquanFbPlanOp(FlatBufferBuilder builder,
      long id,
      int op_nameOffset,
      int inputsOffset,
      int json_attrsOffset) {
    builder.startObject(4);
    IquanFbPlanOp.addId(builder, id);
    IquanFbPlanOp.addJsonAttrs(builder, json_attrsOffset);
    IquanFbPlanOp.addInputs(builder, inputsOffset);
    IquanFbPlanOp.addOpName(builder, op_nameOffset);
    return IquanFbPlanOp.endIquanFbPlanOp(builder);
  }

  public static void startIquanFbPlanOp(FlatBufferBuilder builder) { builder.startObject(4); }
  public static void addId(FlatBufferBuilder builder, long id) { builder.addLong(0, id, 0L); }
  public static void addOpName(FlatBufferBuilder builder, int opNameOffset) { builder.addOffset(1, opNameOffset, 0); }
  public static void addInputs(FlatBufferBuilder builder, int inputsOffset) { builder.addOffset(2, inputsOffset, 0); }
  public static void addJsonAttrs(FlatBufferBuilder builder, int jsonAttrsOffset) { builder.addOffset(3, jsonAttrsOffset, 0); }
  public static int endIquanFbPlanOp(FlatBufferBuilder builder) {
    int o = builder.endObject();
    return o;
  }
}

