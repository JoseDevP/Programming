using BeerShop.Aplication.DTOs;
using FluentValidation;

namespace BeerShop.Aplication.Validators.User
{
    public class UserRegisterValidator : AbstractValidator<UserRegisterDTO>
    {
        public UserRegisterValidator()
        {
            RuleFor(x => x.UserName).NotEmpty().WithMessage("El nombre de usuario no puede estar vacio");
            RuleFor(x => x.UserName).MaximumLength(20).WithMessage("El nombre de usuario no puede ocupar mas de 20 caracteres");

            RuleFor(x => x.Password).NotEmpty().WithMessage("La contraseña de usuario no puede estar vacio");
            RuleFor(x => x.Password)
            .Matches(@"[!@#$%^&*(),.?""\\:;{}|<>]")
            .WithMessage("La contraseña debe contener al menos un carácter especial.");
            RuleFor(x => x.Password).MinimumLength(8).WithMessage("La contraseña no puede ocupar menos de 8 caracteres");
            RuleFor(x => x.Password).MaximumLength(20).WithMessage("La contraseña no puede ocupar mas de 20 caracteres");

            RuleFor(x => x.Email)
            .NotEmpty().WithMessage("El correo electrónico no puede estar vacío")
            .Matches(@"^[^@\s]+@[^@\s]+\.[^@\s]+$").WithMessage("El correo electrónico debe ser válido y contener '@' y '.' en las posiciones correctas");

        }
    }
}
