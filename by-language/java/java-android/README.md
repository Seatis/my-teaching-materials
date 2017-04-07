# Introduction to Android
_This has not been checked, it was built up from notes and working with a single student whose code I saved at the end of the day.  There are a few elements I'm unsure of.  (Eric)_

The JVM is near universal and, under the hood, the Android engine is Dalvik, a JVM.  Hence, knowing Java and also, IntelliJ, the basis of the main Java IDE, makes Android development approachable in this course.

In this lesson we'll cover the basics:-
- setting up the Java IDE
- understanding the basic concepts behind the Java program-to-user-interface
- learn about a particular internet-based service with which we can communicate between Java program users (on different machines).


## Materials &amp; Resources
|Title/Link|Time|
|:---------|---:|
|[Install Android IDE]()||
|[What to .gitIgnore](http://stackoverflow.com/questions/16736856/what-should-be-in-my-gitignore-for-an-android-studio-project)||
|[Troubleshooting Cable issues](http://www.inlovewithandroid.com/android-usb-connection-problems.html)||
|[Setting IntelliJ default Path](http://stackoverflow.com/questions/35100645/intellij-open-project-default-path)||
|[Configuring IntelliJ for Android JVM](https://intellij-support.jetbrains.com/hc/en-us/articles/206544869-Configuring-JVM-options-and-platform-properties)||
|[Android Tutorial - Building My First App](https://developer.android.com/training/basics/firstapp/index.html)||
|[ListView Widget in Android](https://www.tutorialspoint.com/android/android_list_view.htm)||
|[Retrofit - but just with GET, no POST](https://youtu.be/3cN6aJmwMAg)|8:06|
|[Retrofit example](https://www.sitepoint.com/retrofit-a-simple-http-client-for-android-and-java/)||
|[Retrofit (alternative overview)](http://themakeinfo.com/2015/04/retrofit-android-tutorial/)||
|[ListView with 2 elements per row](http://stackoverflow.com/questions/2432951/how-to-display-a-two-column-listview-in-android)||
|[Retrofit - as the server]()||

Other point raised when doing the project


##Review

### Activities
All android apps extend Activities.  They are the basis of screen interaction.  An application consist of 1 or more activities.  They can be imagined as screens, and they *extend* the AppCompatActivity class.  This class provides call back functions.

The main way to access is the `onCreate`.
```java
protected void onCreate (Bundle saveInstanceState) {
  super.onCreate(savedInstranceState);  //calls the parent; must do, if skipped
  setContentView(R.layout.activity_main);  //telling it what it will do; method call; the parameter is the actual view that will be rendered
  // every activity can have its own static view, that you can create in a UI designer
  }
```
  
This approach makes things more manageable for the android engine.

###Layouts
You have a widget designer and you can drag and drop; changing the *Layout* (sits in a folder).  It offers 2 tabs:
- "Design"  - this shows the image of the layout and names the elements
- "Text" - this describes the layout using an xml.

Layouts 
- can be *relative*.  This means that one can set every widget relative to one-another.  When items are relative, in the:
  - *Design*, you'll see a little arrow to denote that such is relative to something else.  
  - *Text*, the value set is `android:relative`.
- Layouts are in the widgets.
- These are linear (in CSS sense); `android:layout_width="match_parent"` then as the parent "wrap_content" instructs the width to match that of the form.
- `layout_weight="1"` for setting proportion with the other elements 

Elements
- `android:id:@+id/` - means create a new id, with no specific name
- `android:@id/nameOfId` which will set the name of the Id.

###EditText
android:text sets the attributes for how the editor would work

### Retrofit
This utility scans a class to encode/decode messages between a server and the remote.  It requires an *empty constructor* (e.g. no parameters) for the data being transferred.  Retrofit will then scan the fields to populate and encode / decode.  For example
```java
Public Class Message  {
  String username;
  String body;
  
  public Message() {}; // this is what will be called
  public Message(String username, String body) { this.username = username; this.body = body;}
}
```

## Exercise Steps

### Create a ListBox

This version is without an `onClick`.
```json
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    package="com.greenfox">
    <uses-permission android:name="android.permission.INTERNET" />

    <application
        android:allowBackup="true"
        android:icon="@mipmap/ic_launcher"
        android:label="@string/app_name"
        android:supportsRtl="true"
        android:theme="@style/AppTheme">
        <activity android:name=".MainActivity">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
    </application>
</manifest>
```

With a listener.
```java
package com.greenfox;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    Button sendButton;
    ListView listView;
    MessagesAdapter msgAdapter;
    ArrayList<Message> messageList;
    EditText textField;
    MsgService service;
    Retrofit retrofit;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        sendButton = (Button) findViewById(R.id.sendButton);
        sendButton.setOnClickListener(MainActivity.this);

        messageList = new ArrayList<>();
        listView = (ListView) findViewById(R.id.listViewID);

        messageList.add(new Message("User Name", "Reconnecting..."));

        msgAdapter = new MessagesAdapter(this, messageList);
        listView.setAdapter(msgAdapter);

        textField = (EditText) findViewById(R.id.editText4);
    }

    @Override
    public void onClick(View v) {
        if (v == sendButton){
            Message m = new Message("User Name", textField.getText().toString());
        }
    }
}
```

### Create a Message Area &amp; &lt;Send&gt; button
This can be done either with a listener, or editing the `onClick` definition in the Layout.

```java
package com.greenfox;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;

public class MessagesAdapter extends ArrayAdapter<Message> {
    public MessagesAdapter(Context context, ArrayList<Message> users) {
        super(context, 0, users);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
	
        // Find the data Get the data item for this position
        Message message = getItem(position);
		
        // Check if an existing view is being reused, otherwise inflate the view
        if (convertView == null) {
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.message, parent, false);
        }
		
        // get pointers to the fields in the table view to then populate
        TextView tvName = (TextView) convertView.findViewById(R.id.textName);
        TextView tvMsg  = (TextView) convertView.findViewById(R.id.textMessage);
		
        // Populate the data into the template view using the data object
        tvName.setText(message.username);
        tvMsg.setText(message.body);
        /* 
		TextView tvDate = (TextView) convertView.findViewById(R.id.textTime);
        tvDate.setText(message.time.toString());
		*/

        // Return the completed view to render on screen
        return convertView;
    }
}
```



### Add in the Retrofit library
Get the retrofit library from [here](//spare.github.io/retrofit/).

Then adjust the dependencies in your `build.gradle` either manually, or using the Project Structure dialogue's Dependencies tab (where you can add the 2 new libraries.)

```json
dependencies {
  ...
  compile 'com.squareup.retrofit2:retrofit:2.1.0'
  compile 'com.squareup.retrofit2:converter-gson:2.1.0'
  ...
}
```
### Wrapper Class
When messages come from the server, they get delivered as json:-

```json
// The request should be sent to the server as:
{
  message: {
    username: "asda",
	body: "asdssda"
  }
}
// If you just put the message in the postMessages method, then it only sends:
{
  username: "asda",
  body: "asda"
}
```
Hence, you'll need a Wrapper class:-
```java
public class Wrapper {
	Message message;
}
```
In the Message Listener (described next), Retrofit will use Wrapper to convert the response's *body* into a Message constructor.  This wrapper will be called in the `onClick` event to Post.

### Message Listener
In this bit, you are defining an *interface* (aka contract).  This is something that in the main code, `Retrofit` will need to know about so that it can build its processor.  Understand that Retrofit reads through the code to construct its implementation of the interface you define.  By defining the interface here, you are telling Retrofit:-
- the datatype, subtype of its `Call` class
- where does the "Wrapper" Class get defined?

```java
package com.greenfox;

import java.util.ArrayList;
import okhttp3.ResponseBody;
import retrofit2.Call;
import retrofit2.Response;
import retrofit2.http.Body;
import retrofit2.http.GET;
import retrofit2.http.POST;

public interface MsgService {
    @GET("/messages")
    Call<ArrayList<Message>> getMessages();
    @POST("/messages")
    Call<ResponseBody> postMessages(@Body Wrapper wrapper);

}


### Amend the main routine to handle such

```java
package com.greenfox;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;

import java.util.ArrayList;


import okhttp3.ResponseBody;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    Button sendButton;
    ListView listView;
    MessagesAdapter msgAdapter;
    ArrayList<Message> messageList;
    EditText textField;
    MsgService service;
    Retrofit retrofit;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        sendButton = (Button) findViewById(R.id.sendButton);
        sendButton.setOnClickListener(MainActivity.this);

        messageList = new ArrayList<>();
        listView = (ListView) findViewById(R.id.listViewID);

        messageList.add(new Message("User Name", "Reconnecting..."));

        msgAdapter = new MessagesAdapter(this, messageList);
        listView.setAdapter(msgAdapter);

        textField = (EditText) findViewById(R.id.editText4);

        retrofit = new Retrofit.Builder()
                .baseUrl("http://zerda-raptor.herokuapp.com/")
                .addConverterFactory(GsonConverterFactory.create())
                .build();


        service = retrofit.create(MsgService.class);

        service.getMessages().enqueue(new Callback<ArrayList<Message>>() {
            @Override
            public void onResponse( 
			  Call<ArrayList<Message>> call, 
			  Response<ArrayList<Message>> response) {
                msgAdapter.clear();
                msgAdapter.addAll(response.body());
			  }

            @Override
            public void onFailure(Call<ArrayList<Message>> call, Throwable t) {
            }
        } );

    }

    @Override
    public void onClick(View v) {
        if (v == sendButton){
            Message m = new Message("User Name", textField.getText().toString());
            msgAdapter.add(m);
            service.postMessages(new Wrapper(m)).enqueue(new Callback<ResponseBody>() {
                @Override
                public void onResponse(
				  Call<ResponseBody> call, 
				  Response<ResponseBody> response) {}

                @Override
                public void onFailure(
				  Call<ResponseBody> call,
				  Throwable t) {}
            });
        }
    }
}
```



### The Server
The service is supplied via herokuapp.  There you'll find a listener set up for this lesson:

The service is listening for messages sent to the endpoint `/messages`:-
- GET
- POST


## Troubleshooting
In assembling this lesson, in the past, we sometimes had issues.  

###Licensing Message
In the `gradle.build` you might need the following to get round a compile file, licnese notification.  

```json
android {
  ...
  packagingOptions {
    exclude 'META-INF/LICENSE'
	exclude 'META-INF/NOTICE'
  }
  ...
}
```

### Android Manifest
You need to permit Android to access the internet by adding the following to the manifest `<uses-permission android:name="android.permission.INTERNET"/>`, hence your manifest might look like this.

```json
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
   package="com.makeinfo.flowerpi" >
<uses-permission android:name="android.permission.INTERNET"/>
    <application
       android:allowBackup="true"
       android:icon="@mipmap/ic_launcher"
       android:label="@string/app_name"
       android:theme="@style/AppTheme" >
        <activity
           android:name=".MainActivity"
           android:label="@string/app_name" >
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />
 
                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
    </application>
 
</manifest>
```




###Message Refresh
The messages might not get repainted every couple of clock cycle, so we added the following for the `onPause` and `onResume` so as to revisit and download messages.
