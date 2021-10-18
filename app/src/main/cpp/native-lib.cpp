//
// Created by engsw on 05/10/2021.
//

#include <jni.h>
#include <string>
#include "sqllite/sqlite3.h"
//#include "sqllite/sqlite3.c"
//#include "sqllite/sqlite3ext.h"


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_myapplication_NativeLibrary_getString(JNIEnv *env, jobject thiz) {
    std::string test = "Hello Android";
    return env->NewStringUTF(test.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_myapplication_NativeLibrary_changeText(JNIEnv *env, jobject thiz) {
    std::string test = "The text changed";
    return env->NewStringUTF(test.c_str());

}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_myapplication_NativeLibrary_sendStatus(JNIEnv *env, jobject thiz,
                                                        jobject sampleDataObj) {
    //std::string name = student
    jclass sampleDataClass = env->GetObjectClass(sampleDataObj);

    jfieldID  sampleIntField= env->GetFieldID(sampleDataClass,"sampleInt", "I");
    jfieldID  sampleBooleanField = env->GetFieldID(sampleDataClass,"sampleBoolean","Z");
    jfieldID  sampleStringField = env->GetFieldID(sampleDataClass,"sampleString","Ljava/lang/String;");
    jfieldID sample = env->GetFieldID(sampleDataClass,"sample", "I");

    jint sampleInt = env->GetIntField(sampleDataObj,sampleIntField);
    jboolean sampleBoolean = env->GetBooleanField(sampleDataObj,sampleBooleanField);


    const char *successString = "Try Again";

    env->SetObjectField(sampleDataObj,sampleStringField,env->NewStringUTF(successString));
    env->SetBooleanField(sampleDataObj,sampleBooleanField,true);
    env->SetIntField(sampleDataObj,sample,8);
    return sampleInt;
}
extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_myapplication_NativeLibrary_onGetObject(JNIEnv *env, jobject thiz) {
    jclass sampleClass = env->FindClass("com/example/myapplication/SampleClass");
    jmethodID  methodId = env->GetMethodID(sampleClass,"<init>","()V");

    // jfieldID fieldId = env->GetFieldID(sampleClass,"s");
    jobject sampleObj = env->NewObject(sampleClass, methodId);

    jfieldID  sampleStringField = env->GetFieldID(sampleClass,"sampleString","Ljava/lang/String;");
    const char *successString = "Completed";

    jfieldID sampleIntField = env->GetFieldID(sampleClass,"sampleInt", "I");

    env->SetObjectField(sampleObj,sampleStringField,env->NewStringUTF(successString));

    return sampleObj;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_NativeLibrary_saveDetails(JNIEnv *env, jobject thiz, jobject user) {
    jclass userClass = env->GetObjectClass(user);

}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_myapplication_NativeLibrary_sendData(JNIEnv *env, jobject thiz, jdoubleArray arr,
                                                      jint a, jfloat b) {
    if (b==a){
        return 1;
    } else{
        return 0;
    }
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_myapplication_NativeLibrary_openDb(JNIEnv *env, jobject thiz, jstring db_path) {

//    sqlite3 *db;
//    sqlite3_stmt *stmt;
//
//    // jstring to const char *
//    const char *database = env->GetStringUTFChars(db_path, 0);
//
//    char *zErrMsg = 0;
//    int rc;
//
//    //SQL ERROR:no such function: json
//    const char * create_sql = "create table user(name, phone)";
//    const char * insert_sql = "insert into user (name, phone) values(\"oz\", json('{\"cell\":\"+491765\", \"home\":\"+498973\"}'))";
//
//   const char * select_sql = "select json_extract(user.phone, '$.cell') from user";
//
//    if (sqlite3_open_v2(database, &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE , NULL) == SQLITE_OK) {
//        // Log.e("database open!!");
//
//        rc = sqlite3_exec(db, create_sql, NULL, NULL, &zErrMsg);
//
//        if( rc != SQLITE_OK ) {
//            //LOGE("SQL ERROR:%s", zErrMsg);
//            sqlite3_free(zErrMsg);
//        } else {
//            //LOGE("CREATE Operation done successfully\n");
//        }
//
//        rc = sqlite3_exec(db, insert_sql, NULL, NULL, &zErrMsg);
//
//        if( rc != SQLITE_OK ) {
//            //LOGE("SQL ERROR:%s", zErrMsg);
//            sqlite3_free(zErrMsg);
//        } else {
//            //LOGE("INSERT Operation done successfully\n");
//        }
//
//        rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, NULL);
//
//        if( rc != SQLITE_OK ) {
//            //LOGE("SQL ERROR:%s", zErrMsg);
//            sqlite3_free(zErrMsg);
//        } else {
//            while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
//                const unsigned char * aaa           = sqlite3_column_text (stmt, 0);
//                const unsigned char * bbb           = sqlite3_column_text (stmt, 1);
//
//                //  LOGE("%s, %s", aaa, bbb);
//            }
//
//            if (rc != SQLITE_DONE) {
//                //LOGE("error: %s", sqlite3_errmsg(db));
//            }
//
//            //  LOGE("SELECT Operation done successfully\n");
//
//            sqlite3_finalize(stmt);
//        }
//
//    } else {
//        //LOGE("database can not open!! : %s", sqlite3_errmsg(db));
//    }
//
//    sqlite3_close(db);
//
}