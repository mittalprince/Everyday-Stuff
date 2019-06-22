import { Validator, NG_VALIDATORS, AbstractControl, ValidatorFn} from '@angular/forms'
import { Input, Directive } from '@angular/core'

@Directive({
    selector: '[appForbiddenName]',
    providers: [{
        provide: NG_VALIDATORS,
        useExisting: ForbiddenValidatorDirective,
        multi: true
    }]
})

export class ForbiddenValidatorDirective implements Validator{
    @Input('appForbiddenName') forbiddenName:  string;
    validate(control: AbstractControl): { [key: string]: any} | null {
        return this.forbiddenName ? forbiddenNameValidator(new RegExp(this.forbiddenName, 'i'))(control) : null

    }
}

export function forbiddenNameValidator(nameRe: RegExp): ValidatorFn{
    return (control: AbstractControl): { [key: string]: any } | null => {
        const forbidden = nameRe.test(control.value);
        return forbidden ? {'forbiddenName': true} : null
    }
}