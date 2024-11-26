using BlogCore.Data;
using BlogCore.Models;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlogCore.DataAccess.Data.Repository.IRepository
{
    public class ArticleRepository : Repository<Article>, IArticleRepository
    {
        private readonly ApplicationDbContext _applicationDbContext;

        public ArticleRepository(ApplicationDbContext applicationDbContext) : base(applicationDbContext)
        {
            _applicationDbContext = applicationDbContext;
        }

        public IQueryable<Article> AsQueryable()
        {
            return _applicationDbContext.Set<Article>().AsQueryable();
        }

        public async Task Update(Article article)
        {
            var obj = await _applicationDbContext.Articles.FirstOrDefaultAsync(c => c.Id == article.Id);
            obj.Name = article.Name;
            obj.Description = article.Description;
            obj.CreationDate = article.CreationDate;
            obj.UrlImagen = article.UrlImagen;
            obj.IdCategory = article.IdCategory;
            obj.Category = article.Category;
        }
    }
}
