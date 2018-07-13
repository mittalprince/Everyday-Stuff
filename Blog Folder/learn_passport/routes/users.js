var express = require('express');
var router = express.Router();
var passport = require('passport');
var LocalStrategy = require('passport-local').Strategy;

var User = require('../models/user');


router.get('/register', function(req, res){
    res.render('register');
});


router.get('/login', function(req, res){
    res.render('login');
});


router.post('/register', function(req, res){
    var name = req.body.name;
    var email = req.body.email;
    var username = req.body.username;
    var password = req.body.password;
    var password2 = req.body.password2;

     {
        User.findOne({email:email, username:username}).then(function(currentUser){
            if(currentUser){
                console.log('user is already registered:',currentUser);
                res.redirect('/users/register')

            }
            else {
                var newUser = new User({
                    name: name,
                    email:email,
                    username: username,
                    password: password
                });

                newUser.save(function(err,user){
                    if(err) throw err;
                    console.log(user);
                })

                res.redirect('/users/login');
            }
        })

    }
});

passport.use(new LocalStrategy(
    function(username, password, done) {
        User.findOne({
            username: username
        }, function(err, user) {
            if (err) {
                return done(err);
            }

            if (!user) {
                return done(null, false);
            }

            if (user.password != password) {
                return done(null, false);
            }
            return done(null, user);
        });
    }
));

passport.serializeUser(function(user, done) {
    done(null, user.id);
});

passport.deserializeUser(function(id, done) {
    User.findById(id, function(err, user) {
        done(err, user);
    });
});

router.post('/login',
    passport.authenticate('local', {successRedirect:'/', failureRedirect:'/users/login'}),
    function(req, res) {
        res.redirect('/users/login');
    });

router.get('/logout', function(req, res){
    req.logout();

    res.redirect('/users/login');
});

module.exports = router;