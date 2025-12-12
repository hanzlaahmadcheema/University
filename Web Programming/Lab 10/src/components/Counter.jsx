
import { useState } from 'react';
import PropTypes from 'prop-types';
import Button from './Button';

const Counter = ({ initialCount = 0 }) => {
  const [count, setCount] = useState(initialCount);

  return (
    <div className="card counter-card">
      <h2 className="card-title">Counter</h2>
      <div className="count-display">{count}</div>
      <div className="button-group">
        <Button 
          label="Decrease" 
          onClick={() => setCount(count - 1)} 
          variant="secondary"
        />
        <Button 
          label="Increase" 
          onClick={() => setCount(count + 1)} 
          variant="primary"
        />
      </div>
    </div>
  );
};

Counter.propTypes = {
  initialCount: PropTypes.number,
};

export default Counter;
