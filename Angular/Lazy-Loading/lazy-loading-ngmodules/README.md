# TestingApp

This project was generated with [Angular CLI](https://github.com/angular/angular-cli) version 7.2.3.

## Development server

Run `ng serve` for a dev server. Navigate to `http://localhost:4200/`. The app will automatically reload if you change any of the source files.

## Code scaffolding

Run `ng generate component component-name` to generate a new component. You can also use `ng generate directive|pipe|service|class|guard|interface|enum|module`.

## Build

Run `ng build` to build the project. The build artifacts will be stored in the `dist/` directory. Use the `--prod` flag for a production build.

## Running unit tests

Run `ng test` to execute the unit tests via [Karma](https://karma-runner.github.io).

## Running end-to-end tests

Run `ng e2e` to execute the end-to-end tests via [Protractor](http://www.protractortest.org/).

## Further help

To get more help on the Angular CLI use `ng help` or go check out the [Angular CLI README](https://github.com/angular/angular-cli/blob/master/README.md).

## Lazy Loading

>Lazy loading is a technique in Angular that allows you to load JavaScript components asynchronously when a specific route is activated. This can add some initial performance during the initial load, especially if you have many components with complex routing.

Lazy loading helps us to download the web pages in chunks instead of downloading everything in a big bundle.

> Why we need this? 
* NgModules are eagerly loaded, which means that as soon as the app loads, so do all the NgModules, whether or not they are immediately necessary. For large apps with lots of routes, consider lazy loading—a design pattern that loads NgModules as needed. Lazy loading helps keep initial bundle sizes smaller, which in turn helps decrease load times.

>How to do **Lazy Loading** ?

There are three main steps to setting up a lazy loaded feature module:

* Create the feature module.
* Create the feature module’s (lazy module) routing module.
* Configure the routes.

>For refernce: [KhoPhi's Blog](https://blog.khophi.co/angular-module-lazy-loading-like-pro/), [Angular-Tutorial](https://angular.io/guide/lazy-loading-ngmodules), [AngularFireBase](https://angularfirebase.com/lessons/how-to-lazy-load-components-in-angular-4-in-three-steps/).