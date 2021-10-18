package com.example.myapplication;

public class NativeLibrary {

    public native String getString();

    public native String changeText();

   public native String openDb(String db_path);

    public native int sendStatus(SampleClass sampleClass);

    public native SampleClass onGetObject();

    public native void saveDetails(User user);

    public native int sendData(double[] arr, int a, float b);
}
