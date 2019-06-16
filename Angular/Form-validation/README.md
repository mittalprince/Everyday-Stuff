# FormValidation

This project was generated with [Angular CLI](https://github.com/angular/angular-cli) version 8.0.2.

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


> Angular provides two ways to work with forms: *template-driven forms* and *reactive forms*, the latter also sometimes called model-driven forms. With template-driven forms, the default way to work with forms in Angular, template directives are used to build an internal representation of the form. With reactive forms, by contrast, you build your own representation of a form in the component class.

* Reactive forms were introduced with Angular 2.

### What are Angular Reactive Forms?
>Reactive forms are also known as model-driven forms. This means that the HTML content changes depending on the code in the component.

* While reactive forms can be a tad more complex to work with in the beginning, they allow for much more flexibility and they also help keep your logic in the component class and your templates simple.

* Use the reactive forms approach in case the form shall support dynamic data structures and logic. Examples are dynamic survey forms, forms to add/delete 0..n tags or phone numbers, forms providing different validation for different user roles, etc.


### What are Angular Template-Driven Forms?
>Template-driven forms are driven by derivatives in the template. This means that you will see derivatives such as `ngModel` in the template as opposed to the code. 

* Use template-driven forms when developing static forms. Static means the structure and logic of a form is fix. E.g. the number of form fields does not vary, form validation rules are the same for different user roles, etc. In the template-driven approach the form structure and logic is mainly implemented in HTML. Based on this a representation of the form in TypeScript is generated automatically.

* Examples are login forms, reset password forms, forms to enter an

## Difference in Reactive and Template-Driven Form

| *Points*            | *REACTIVE*                                 | *TEMPLATE-DRIVEN*                     |
|--------------------|-------------------------------------------|--------------------------------------|
| Setup (form model) | More explicit, created in component class | Less explicit, created by directives |
| Data model         | Structured                                | Unstructured                         |
| Predictability     | Synchronous                               | Asynchronous                         |
| Form validation    | Functions                                 | Directives                           |
| Mutability         | Immutable                                 | Mutable                              |
| Scalability        | Low-level API access                      | Abstraction on top of APIs  
| Module | ReactiveFormsModule | FormsModule

> *Reactive Form over Template-Driven Forms :* Although template forms are easier to create, they become a challenge when you want to do unit testing, because testing requires the presence of a DOM. It's easier to write unit tests in reactive forms since all the form code and functionality is contained in the component. However, reactive forms require more coding implementation in the component

> With the template driven approach you basically apply directives, such as ngModel, in your template. Based on these directives Angular will create formcontrol objects. This approach is good for building simple forms with basic validation (required, minlength, maxlength,...).

> With the reactive approach you basically need to create new instances of the formcontrols and formcontrolgroups in your component. Reactive forms are also the best choice for building more complex forms and are better in case you have the intention to implement unit testing for your forms.

> Form Control State

| *State*                            | *Class if true* | *Class if false* |
|----------------------------------|---------------|----------------|
| The control has been visited.    | ng-touched    | ng-untouched   |
| The control's value has changed. | ng-dirty      | ng-pristine    |
| The control's value is valid.    | ng-valid      | ng-invalid     |

* `dirty` is `true` if the user has changed the value of the control.

* A controls is said to be `touched` if the the user focused on the control and then focused on something else. For example by clicking into the control and then pressing tab or clicking on another control in the form.

> The difference between `touched` and `dirty` is that with touched the user doesn’t need to actually change the value of the input control.

* `valid` is `true` of the field doesn’t have any validators or if all the validators are passing.

> Reference [Reactive Form by alligator](https://alligator.io/angular/reactive-forms-introduction/), [Angular Tutorials](https://angular.io/guide/reactive-forms), [Blog](https://www.ryadel.com/en/angular-forms-template-driven-model-driven-reactive-pros-cons-tutorial-guide/), [CodeCrdft](https://codecraft.tv/courses/angular/forms/model-driven-validation/), [Custom Validator](https://dzone.com/articles/how-to-create-custom-validators-in-angular), [concretepage](https://www.concretepage.com/angular-2/angular-2-4-minlength-and-maxlength-validation-example).