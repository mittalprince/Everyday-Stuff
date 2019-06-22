import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms'
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { routingComponent } from './app-routing.module'

// Validators -------------------------------

import { EqualToValidatorDirective } from './partials/validators/equalTo-validator.directive'
import { ForbiddenValidatorDirective, forbiddenNameValidator } from './partials/validators/forbidden-name-validator.directive'

// Components -------------------------------
import { headerComponent } from './../app/partials/header/header.component'

@NgModule({
  declarations: [
    AppComponent,
    headerComponent,
    routingComponent,
    EqualToValidatorDirective,
    ForbiddenValidatorDirective
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
