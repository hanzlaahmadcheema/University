import React from 'react';

export default function Header(props) {
  return (
    <header className="site-header">
      <div className="container">
        <h1 className="site-title">{props.title}</h1>
        {props.subtitle && <p className="site-subtitle">{props.subtitle}</p>}
      </div>
    </header>
  );
}
