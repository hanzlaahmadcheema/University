import React from 'react';

export default function ProductCard(props) {
  const { product, onAddToCart } = props;

  return (
    <article className="product-card">
      <img src={product.imageUrl} alt={product.title} className="product-image" />
      <h3 className="product-title">{product.title}</h3>
      <p className="product-price">${product.price}</p>
      <div className="product-actions">
        <button
          className="btn btn-primary"
          onClick={() => onAddToCart && onAddToCart(product)}
        >
          Add to Cart
        </button>
      </div>
    </article>
  );
}
