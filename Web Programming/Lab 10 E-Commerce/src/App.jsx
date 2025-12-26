import React from 'react';
import Header from './components/Header';
import ProductList from './components/ProductList';
import Footer from './components/Footer';
import SearchBox from './components/SearchBox';

const PRODUCTS = [
  { id: 1, title: 'White T-Shirt', price: 19.99, imageUrl: 'https://images.unsplash.com/photo-1521572163474-6864f9cf17ab?auto=format&fit=crop&w=600&q=80' },
  { id: 2, title: 'Blue Jeans', price: 49.99, imageUrl: 'https://images.unsplash.com/photo-1602293589946-8b245fa3ac43?auto=format&fit=crop&w=600&q=80' },
  { id: 3, title: 'Sneakers', price: 69.99, imageUrl: 'https://images.unsplash.com/photo-1542291026-7eec264c27ff?auto=format&fit=crop&w=600&q=80' }
];

export default function App() {
  function handleAddToCart(product) {
    console.log('Add to cart clicked for:', product);
    alert(`Requested to add ${product.title} to cart (demo).`);
  }

  function handleSearch(query) {
    console.log('Search query:', query);
    alert(`Search for: ${query}`);
  }

  return (
    <div>
      <Header
        title="My E-Shop"
        subtitle="Quality goods, simple site"
      />
      <main className="container main-content">
        <SearchBox onSearch={handleSearch} />
        <h2>Products</h2>
        <ProductList products={PRODUCTS} onAddToCart={handleAddToCart} />
      </main>
      <Footer />
    </div>
  );
}
