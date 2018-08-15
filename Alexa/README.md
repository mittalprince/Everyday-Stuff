# Learn Alexa

* Learn to build [Fact Skill](https://learn.amazonfutureengineer.com/alexa/fact-skill/#/tasks/3)

* Learn to build [First Skill](https://www.codecademy.com/courses/learn-alexa-skills-kit/lessons/intro-to-alexa/exercises/connect-lambda-arn?action=resume_content_item&course_redirect=learn-alexa)

## How Alexa works

![First](https://raw.githubusercontent.com/mittalprince/Everyday-Stuff/master/Alexa/images/alexa.png)

## Learn Lamba Function

* One of the first things we will do is include the Alexa-SDK library in our Lambda function — this makes Alexa's core features available in our Lambda function. We do this with the following require() statement:

```js
var Alexa = require("alexa-sdk");
```
* When Alexa sends a request to your Lambda function, the script needs to handle those requests. All of these requests are handled by an object named handlers. Like this:

```js
var handlers = {


}
```

* If we wanted to handle an intent called `<YOUR_INTENT_NAME>`, we could add it to our handlers as a key of the same name. As long as the name of the handler function matches the name of the Intent, the Alexa SDK will automatically map the intent requested to the appropriate handler.

```js
"YOUR_INTENT_NAME": function () {

 }
```

* `this.response` contains functions used to set up a response from Alexa, like this:

```js
this.response.speak("Hello, welcome to Codecademy!")
```
* Once the response is set up, we use `this.emit(':responseReady')` to send our response to the user's Alexa device.

```js
'LaunchRequest': function () {
    this.response.speak("Hello, welcome to Codecademy!");
    this.emit(':responseReady');
  }
```
> Together, these two lines `(.speak() and .emit(':responseReady'))` set up and send the response to the user's Alexa device. One thing to note, is that .speak() generates a response and then instructs Alexa to close the session.

* The Alexa SDK library includes the `.response.speak()` and `.emit()` methods, which together, generate a JSON response when Alexa triggers the `<YOUR_INTENT_NAME>`.

* Alexa then parses the JSON, and speaks the words in the "ssml" value from the outputSpeech object.

> `this.response.speak()` sets up a response to the user and ends the session.

* Chaining `.listen()` to the `.speak()` response keeps the session open and opens the michrophone to listen for a user's response.

* You can provide an optional string as an argument to the `.listen()` method, which will be used by Alexa to reprompt the user if no response was detected.

* You use `this.emit(':responseReady')` to send your response to a user's Alexa device.

> SSML stands for Speech Synthesis Markup Language.You can think of SSML as HTML for speech. It is a markup language that provides a standard way to mark up text for the generation of synthetic speech, and something you will find useful while creating skills. 

#### Lambda Handler Function 

* The Lambda function triggers the exports.handler() function every time an Alexa skill requests it.

```js
exports.handler = function(event, context, callback) {

}
```

##### Set up the Alexa Object

* Inside the Lambda handler function, we will add the following line: 
```js 
var alexa = Alexa.handler(event, context);
```
* This will set up an alexa object for us to work with, and accepts two parameters:

    * event – AWS Lambda uses this parameter to pass in event data to the handler.
    * context – AWS Lambda uses this parameter to provide your handler the runtime information of the Lambda function that is executing.

##### Register Handlers

* We need to give our alexa object, from step one, the list of handlers that we created. We do this with the `.registerHandlers()` method in the alexa object.

```js 
alexa.registerHandlers(handlers);
```
##### Start Alexa Code

* Finally, we will use the execute function from the alexa object to run our skill's logic.

```js
alexa.execute();
```
#### Collecting User Input

>A slot is an argument to an intent that gives Alexa more information about that request. For example: “Alexa, ask History Buff what happened on June third”. In this statement, “June third” is the value of a date slot that interprets the request.

* You can access user input values from Alexa's JSON request using the following:

```js
this.event.request.intent.slots.yourSlotName.value
```
> Session attributes allow Alexa to remember and update user-provided details throughout a session. You can think of session attributes as being similar to variables that store information about the program, except values stored in session attributes persist throughout a session. 

* Session attributes are stored in the response that your skill receives from Alexa as a JSON.

* We can create and edit attribute fields by accessing their key. Inside of the Lambda function, you can access session attribute values using `this.attributes` .

```js
this.attributes['yourAttribute'] = 'value';
```

* In the example above, we create a field in `attributes` and save the string `'value'` to it. `this` references the alexa object that's instantiated in the `export.handlers` function.

> Like variables, session attributes hold values that we can change after we've created them.

#### To use DynaomoDB 

> Why we use it? Once you have session attributes that persist throughout a session, it’s helpful to save them to a database. The information that is saved within a session can be accessed in subsequent sessions.

* A database holds and organizes information so that it can be easily accessed, managed, and updated. Databases save information sent from the frontend of our skill and then can respond with that information later. Our Lambda function manages that relationship in the backend.

![Second](https://raw.githubusercontent.com/mittalprince/Everyday-Stuff/master/Alexa/images/DynaomoDB.png)