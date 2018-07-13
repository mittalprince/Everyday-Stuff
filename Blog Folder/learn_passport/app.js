var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');
var exphbs = require('express-handlebars');
var expressValidator = require('express-validator');
var flash = require('connect-flash');
var session = require('express-session');
var passport = require('passport');
var mongo = require('mongodb');
var mongoose = require('mongoose');

mongoose.connect('mongodb://mittalprince:prince25@ds235181.mlab.com:35181/example_1',function(){
    console.log('connected to mongodb');
});


var routes = require('./routes/index');
var users = require('./routes/users');

var app = express();

app.set('views', path.join(__dirname , 'views'));
app.engine('handlebars', exphbs({defaultLayout:'layout'}));
app.set('view engine', 'handlebars');

app.use(express.static(path.join(__dirname,'public')));

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended:false}));
app.use(cookieParser());

app.use(session({
    secret: 'secret',
    saveUninitialized:true,
    resave: true
}));

app.use(passport.initialize());
app.use(passport.session());

app.use(function(req,res,next){
    res.locals.user = req.user || null;
    next();
})

app.use('/', routes);
app.use('/users', users);

app.set('port', (process.env.PORT || 8000));
app.listen(app.get('port'), function(){
    console.log('Server listening on port ' +app.get('port'));
});
