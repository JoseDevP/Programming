using Backend.DTOs;
using FluentValidation;

namespace Backend.Validators
{
    public class BrandInsertValidator : AbstractValidator<BrandInsertDTO>
    {
        public BrandInsertValidator() 
        {
            RuleFor(x => x.Name).NotEmpty().WithMessage("El nombre es obligatorio");
            RuleFor(x => x.Name).Length(2, 20).WithMessage("El nombre debe medir 2 - 20 caracteres");
        }
    }
}
