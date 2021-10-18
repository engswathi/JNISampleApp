package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.AppCompatButton;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    static {
        System.loadLibrary("native-library");
    }

    TextView tvPassObject,tvPassData,tvGetObject,tvGetString,tvOpenDb;
    AppCompatButton btnPassObject,btnPassData,btnGetObject,btnSubmit,btnGetString,btnOpenDb;
    EditText emailEditText,nameEditText;
    NativeLibrary nativeLibrary;
    User user;
    SampleClass sampleClass;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initializeViews();

        nativeLibrary = new NativeLibrary();

        //created values for sample class
        sampleClass = new SampleClass();
        sampleClass.setSampleInt(0);
        sampleClass.setSampleString("Failed");
        sampleClass.setSampleBoolean(true);
        sampleClass.setSample(4);



        btnGetString.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String newString = nativeLibrary.getString();
                tvGetString.setText(newString);
            }
        });

        //stringTextView.setText(nativeLibrary.getString());
        btnPassObject.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //btnPassObject.setText(nativeLibrary.changeText());
                int status = nativeLibrary.sendStatus(sampleClass);
                if (status==0){

                    tvPassObject.setText(sampleClass.getSampleString() + " " + sampleClass.getSample());
                }else {
                    tvPassObject.setText("Failed");
                }

            }
        });

        btnPassData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                double[] arr ={2,3,5,8};
                int a = 8;
                float b = 2.6f;
             // int num =  nativeLibrary.sendData(2,8,4);

                int num =  nativeLibrary.sendData(arr,a,b);
                if (num ==1){
                    tvPassData.setText("Success");
                }else {
                    tvPassData.setText("Failed");
                }

            }
        });

        btnGetObject.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SampleClass sampleClass = nativeLibrary.onGetObject();
                tvGetObject.setText(sampleClass.getSampleString());
              //  String success = nativeLibrary.openDb(MainActivity.this.getApplicationInfo().dataDir);
            }
        });

        btnOpenDb.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String success = nativeLibrary.openDb(MainActivity.this.getApplicationInfo().dataDir);
            }
        });

//        btnSubmit.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                user = new User();
//                user.setName(nameEditText.getText().toString());
//                user.setEmail(emailEditText.getText().toString());
//                nativeLibrary.saveDetails(user);
//                nameEditText.setText("");
//                emailEditText.setText("");
//            }
//        });
    }

    private void initializeViews() {
        tvOpenDb        = findViewById(R.id.tvOpenDb);
        tvGetString     = findViewById(R.id.tvGetString);
        tvPassObject    = findViewById(R.id.tvPassObject);
        tvPassData      = findViewById(R.id.tvPassData);
        tvGetObject     = findViewById(R.id.tvGetObject);
        btnPassObject   = findViewById(R.id.btnPassObject);
        btnPassData     = findViewById(R.id.btnPassData);
        btnGetObject    = findViewById(R.id.btnGetObject);
        btnGetString    = findViewById(R.id.btnGetString);
        btnOpenDb       = findViewById(R.id.btnOpenDb);

//        emailEditText   = findViewById(R.id.emailEditText);
//        nameEditText    = findViewById(R.id.nameEditText);
//        btnSubmit       = findViewById(R.id.btnSubmit);
    }

}