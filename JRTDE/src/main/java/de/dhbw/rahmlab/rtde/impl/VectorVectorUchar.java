/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package de.dhbw.rahmlab.rtde.impl;

public class VectorVectorUchar extends java.util.AbstractList<VectorUchar> implements java.util.RandomAccess {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected VectorVectorUchar(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(VectorVectorUchar obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        ViconDataStreamSDKSwigJNI.delete_VectorVectorUchar(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public VectorVectorUchar(VectorUchar[] initialElements) {
    this();
    reserve(initialElements.length);

    for (VectorUchar element : initialElements) {
      add(element);
    }
  }

  public VectorVectorUchar(Iterable<VectorUchar> initialElements) {
    this();
    for (VectorUchar element : initialElements) {
      add(element);
    }
  }

  public VectorUchar get(int index) {
    return doGet(index);
  }

  public VectorUchar set(int index, VectorUchar e) {
    return doSet(index, e);
  }

  public boolean add(VectorUchar e) {
    modCount++;
    doAdd(e);
    return true;
  }

  public void add(int index, VectorUchar e) {
    modCount++;
    doAdd(index, e);
  }

  public VectorUchar remove(int index) {
    modCount++;
    return doRemove(index);
  }

  protected void removeRange(int fromIndex, int toIndex) {
    modCount++;
    doRemoveRange(fromIndex, toIndex);
  }

  public int size() {
    return doSize();
  }

  public VectorVectorUchar() {
    this(ViconDataStreamSDKSwigJNI.new_VectorVectorUchar__SWIG_0(), true);
  }

  public VectorVectorUchar(VectorVectorUchar other) {
    this(ViconDataStreamSDKSwigJNI.new_VectorVectorUchar__SWIG_1(VectorVectorUchar.getCPtr(other), other), true);
  }

  public long capacity() {
    return ViconDataStreamSDKSwigJNI.VectorVectorUchar_capacity(swigCPtr, this);
  }

  public void reserve(long n) {
    ViconDataStreamSDKSwigJNI.VectorVectorUchar_reserve(swigCPtr, this, n);
  }

  public boolean isEmpty() {
    return ViconDataStreamSDKSwigJNI.VectorVectorUchar_isEmpty(swigCPtr, this);
  }

  public void clear() {
    ViconDataStreamSDKSwigJNI.VectorVectorUchar_clear(swigCPtr, this);
  }

  public VectorVectorUchar(int count, VectorUchar value) {
    this(ViconDataStreamSDKSwigJNI.new_VectorVectorUchar__SWIG_2(count, VectorUchar.getCPtr(value), value), true);
  }

  private int doSize() {
    return ViconDataStreamSDKSwigJNI.VectorVectorUchar_doSize(swigCPtr, this);
  }

  private void doAdd(VectorUchar x) {
    ViconDataStreamSDKSwigJNI.VectorVectorUchar_doAdd__SWIG_0(swigCPtr, this, VectorUchar.getCPtr(x), x);
  }

  private void doAdd(int index, VectorUchar x) {
    ViconDataStreamSDKSwigJNI.VectorVectorUchar_doAdd__SWIG_1(swigCPtr, this, index, VectorUchar.getCPtr(x), x);
  }

  private VectorUchar doRemove(int index) {
    return new VectorUchar(ViconDataStreamSDKSwigJNI.VectorVectorUchar_doRemove(swigCPtr, this, index), true);
  }

  private VectorUchar doGet(int index) {
    return new VectorUchar(ViconDataStreamSDKSwigJNI.VectorVectorUchar_doGet(swigCPtr, this, index), false);
  }

  private VectorUchar doSet(int index, VectorUchar val) {
    return new VectorUchar(ViconDataStreamSDKSwigJNI.VectorVectorUchar_doSet(swigCPtr, this, index, VectorUchar.getCPtr(val), val), true);
  }

  private void doRemoveRange(int fromIndex, int toIndex) {
    ViconDataStreamSDKSwigJNI.VectorVectorUchar_doRemoveRange(swigCPtr, this, fromIndex, toIndex);
  }

}
