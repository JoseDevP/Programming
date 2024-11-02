using Backend.DTOs.Brand;
using FluentValidation;

namespace Backend.Validators.Brand
{
    public class BrandUpdateValidator : AbstractValidator<BrandUpdateDTO>
    {
        public BrandUpdateValidator()
        {
            RuleFor(x => x.Name).NotEmpty().WithMessage("El nombre es obligatorio");
            RuleFor(x => x.Name).Length(2, 20).WithMessage("El nombre debe medir 2 - 20 caracteres");
        }
    }
}
