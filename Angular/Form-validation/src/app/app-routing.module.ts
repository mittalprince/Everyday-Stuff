import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { reactiveComponent } from './reactive/reactive.component'
import { templateDrivenComponent } from './template-driven/template-driven.component'
import { landingComponent } from './landing/landing.component'
import { TemplateComponent } from './issue-template/template.component'
import { ShimmerTemplateComponent } from './issue-template/shimmering-template/shimmering-template.component'
import { TextEditorComponent } from './text-editor/text-editor.component' 
import { CalenderComponent } from './calender/calender.component';

const routes: Routes = [
  {path: '', redirectTo: '/home' , pathMatch: 'full'},
  {path:'home', component:landingComponent},
  {path:'reactive', component: reactiveComponent},
  {path:'template-driven', component: templateDrivenComponent},
  {path: 'template', component: TemplateComponent},
  {path: 'shimmer-template', component: ShimmerTemplateComponent},
  {path: 'editor', component: TextEditorComponent},
  {path: 'calender', component: CalenderComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }

export const routingComponent = [
  reactiveComponent,
  templateDrivenComponent,
  landingComponent,
  TemplateComponent,
  ShimmerTemplateComponent,
  TextEditorComponent,
  CalenderComponent
]
