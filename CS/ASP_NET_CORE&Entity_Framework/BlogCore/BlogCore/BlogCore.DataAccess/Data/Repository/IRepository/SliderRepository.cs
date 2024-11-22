using BlogCore.Data;
using BlogCore.Models;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlogCore.DataAccess.Data.Repository.IRepository
{
    public class SliderRepository : Repository<Slider>, ISliderRepository
    {
        private readonly ApplicationDbContext _applicationDbContext;

        public SliderRepository(ApplicationDbContext applicationDbContext) : base(applicationDbContext)
        {
            _applicationDbContext = applicationDbContext;
        }

        public async Task Update(Slider slider)
        {
            var obj = await _applicationDbContext.Sliders.FirstOrDefaultAsync(c => c.Id == slider.Id);
            obj.Name = slider.Name;
            obj.State = slider.State;
            obj.UrlImage = slider.UrlImage;
        }
    }
}
