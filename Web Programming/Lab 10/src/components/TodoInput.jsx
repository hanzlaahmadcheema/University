
import { useState } from 'react';
import PropTypes from 'prop-types';
import Button from './Button';

const TodoInput = ({ onAdd }) => {
  const [inputValue, setInputValue] = useState('');

  const handleAdd = () => {
    if (inputValue.trim()) {
      onAdd(inputValue);
      setInputValue('');
    }
  };

  const handleKeyDown = (e) => {
    if (e.key === 'Enter') {
      handleAdd();
    }
  };

  return (
    <div className="card todo-input-card">
      <h2 className="card-title">New Task</h2>
      <div className="input-group">
        <input
          type="text"
          className="styled-input"
          value={inputValue}
          onChange={(e) => setInputValue(e.target.value)}
          onKeyDown={handleKeyDown}
          placeholder="What needs to be done?"
        />
        <Button label="Add" onClick={handleAdd} variant="primary" />
      </div>
    </div>
  );
};

TodoInput.propTypes = {
  onAdd: PropTypes.func.isRequired,
};

export default TodoInput;
