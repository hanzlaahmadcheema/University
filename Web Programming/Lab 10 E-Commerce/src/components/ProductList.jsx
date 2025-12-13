import React from 'react';
import ProductCard from './ProductCard';

export default function ProductList(props) {
  const { products = [], onAddToCart } = props;

  return (
    <section className="product-list">
      {products.map((p) => (
        <ProductCard key={p.id} product={p} onAddToCart={onAddToCart} />
      ))}
    </section>
  );
}
