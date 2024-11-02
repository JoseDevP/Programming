using Backend.DTOs;
using FluentValidation;

namespace Backend.Validators.User
{
    public class UserLogingValidator : AbstractValidator<UserLogingDTO>
    {
        public UserLogingValidator()
        {
            RuleFor(x => x.UserName).NotEmpty().WithMessage("El nombre de usuario no puede estar vacio");
            RuleFor(x => x.UserName).MaximumLength(20).WithMessage("El nombre de usuario no puede ocupar mas de 20 caracteres");

            RuleFor(x => x.Password).NotEmpty().WithMessage("La contraseña de usuario no puede estar vacio");
            RuleFor(x => x.Password)
            .Matches(@"[!@#$%^&*(),.?""\\:;{}|<>]")
            .WithMessage("La contraseña debe contener al menos un carácter especial.");
            RuleFor(x => x.Password).MinimumLength(8).WithMessage("La contraseña no puede ocupar menos de 8 caracteres");
            RuleFor(x => x.Password).MaximumLength(20).WithMessage("La contraseña no puede ocupar mas de 20 caracteres");

        }
    }
}
