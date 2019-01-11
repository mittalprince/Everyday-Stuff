var express = require('express');
var request = require('request');
var ejs = require('ejs');

var app = express();
var port = 3002;

app.get('/', function(req,res){
	let data = [];
	let url = 'https://api.myjson.com/bins/blxqf';
	request(url, function(req, response, body){
		data = JSON.stringify(body);
		res.render('index');
	})
})

app.set('view engine', 'ejs');
app.use(express.static('public'));

app.listen(port, function(){
	console.log(`Server is listening on http://localhost:${port}`);
});