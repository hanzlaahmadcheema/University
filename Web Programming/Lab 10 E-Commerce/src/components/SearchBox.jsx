import React from 'react';

export default function SearchBox({ onSearch }) {
  function handleSubmit(e) {
    e.preventDefault();
    const form = e.target;
    const input = form.elements['q'];
    const q = input ? input.value : '';
    
    if (onSearch) onSearch(q);
  }

  return (
    <form className="search-box" onSubmit={handleSubmit} style={{ marginBottom: '20px' }}>
      <input name="q" placeholder="Search products..." style={{ padding: '8px', marginRight: '8px', width: '200px' }} />
      <button type="submit" className="btn btn-primary">Search</button>
    </form>
  );
}
