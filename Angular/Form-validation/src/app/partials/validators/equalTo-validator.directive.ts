import { Validator, AbstractControl, NG_VALIDATORS, ValidatorFn, FormGroup} from '@angular/forms'
import { Directive, Input } from '@angular/core'

@Directive({
    selector: '[appEqualToValidator]',
    providers: [{
        provide: NG_VALIDATORS,
        useExisting: EqualToValidatorDirective,
        multi: true
    }]
})

export class EqualToValidatorDirective implements Validator{

    @Input() appEqualToValidator: string;
    validate(control: AbstractControl): { [key: string]: any} | null {
        return (control.value) ? EqualToValidator(this.appEqualToValidator)(control) : null
    }
}

export function EqualToValidator( matchControlName: any): ValidatorFn {
    return (control : AbstractControl): { [key: string]: any } | null => {
        const compareTo = control.parent.controls[matchControlName].value
        if(compareTo !== control.value){
            return {'equalTo': true}
        }
        return null
    }
}

export function MustMatch(matchControlName: string){
    return (control: AbstractControl): { [key: string]: any} | null => {
       if(control.value){
           const compareTo = control.parent.controls[matchControlName].value
           if(compareTo !== control.value){
                return {'equalTo': true}
           }
           return null
       }
       return null
    }
}