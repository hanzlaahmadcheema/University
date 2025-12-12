import React from 'react';
import Header from './components/Header';
import ProductList from './components/ProductList';
import Footer from './components/Footer';
import SearchBox from './components/SearchBox';

const PRODUCTS = [
  { id: 1, title: 'White T-Shirt', price: 19.99, imageUrl: '/images/tshirt.jpg' },
  { id: 2, title: 'Blue Jeans', price: 49.99, imageUrl: '/images/jeans.jpg' },
  { id: 3, title: 'Sneakers', price: 69.99, imageUrl: '/images/sneakers.jpg' }
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
