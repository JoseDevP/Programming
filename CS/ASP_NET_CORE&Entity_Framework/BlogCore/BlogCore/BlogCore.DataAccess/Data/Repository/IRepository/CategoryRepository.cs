﻿using BlogCore.Data;
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
    public class CategoryRepository : Repository<Category>, ICategoryRepository
    {
        private readonly ApplicationDbContext _applicationDbContext;

        public CategoryRepository(ApplicationDbContext applicationDbContext) : base(applicationDbContext)
        {
            _applicationDbContext = applicationDbContext;
        }

        public IEnumerable<SelectListItem> GetCategoryList()
        {
            return _applicationDbContext.Categories.Select(i=> new SelectListItem()
            {
                Text = i.Name,
                Value = i.Id.ToString()
            });
        }

        public async Task Update(Category category)
        {
            var obj = await _applicationDbContext.Categories.FirstOrDefaultAsync(c => c.Id == category.Id);
            obj.Name = category.Name;
            obj.Order = category.Order;
        }
    }
}
