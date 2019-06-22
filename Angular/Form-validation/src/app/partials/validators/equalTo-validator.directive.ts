import { Validator, AbstractControl, NG_VALIDATORS, ValidatorFn} from '@angular/forms'
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
    validate(control: AbstractControl): { [key: string]: any} | any {
        return (control.value) ? EqualToValidator(control.parent.controls[this.appEqualToValidator].value)(control) : null
    }
}

export function EqualToValidator( password: any): ValidatorFn {
    return (control : AbstractControl): { [key: string]: any } | null => {
        if(password !== control.value){
            return {'equalTo': true}
        }
        return null
    }
}