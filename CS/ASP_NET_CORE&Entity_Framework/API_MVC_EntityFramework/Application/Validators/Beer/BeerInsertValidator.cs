using Core.DTOs.Beer;
using FluentValidation;

namespace BeerShop.Aplication.Validators.Beer
{
    public class BeerInsertValidator : AbstractValidator<BeerInsertDTO>
    {
        public BeerInsertValidator()
        {
            RuleFor(x => x.Name).NotEmpty().WithMessage("El nombre es obligatorio");
            RuleFor(x => x.Name).Length(2, 20).WithMessage("El nombre debe medir 2 - 20 caracteres");
            RuleFor(x => x.BrandID).NotNull().WithMessage(x => "La marca es obligatoria");
            RuleFor(x => x.BrandID).GreaterThan(0).WithMessage(x => "Error con el valor de la marca");
            RuleFor(x => x.Alcohol).GreaterThan(0).WithMessage(x => "El {PropertyName} debe de ser mayor a 0");
        }
    }
}
