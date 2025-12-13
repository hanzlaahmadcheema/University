
import { useState } from 'react';
import NameCard from './components/NameCard';
import Counter from './components/Counter';
import TodoInput from './components/TodoInput';
import Button from './components/Button';
import './App.css'; 

function App() {
  const [todos, setTodos] = useState(['Learn React', 'Master Props']);

  const addTodo = (task) => {
    setTodos([...todos, task]);
  };

  return (
    <div className="app-container">
      <h1>React Lab 10 Assignments</h1>
      
      <div className="grid-container">

        <NameCard name="Hanzla Ahmad" />


        <Counter initialCount={10} />


        <div className="card todo-section">
          <h2 className="card-title">Todo List</h2>
          <TodoInput onAdd={addTodo} />
          <ul className="todo-list">
            {todos.map((todo, index) => (
              <li key={index} className="todo-item">
                {todo}
              </li>
            ))}
          </ul>
        </div>
        

        <div className="card button-showcase">
           <h2 className="card-title">Reusable Button Demo</h2>
           <Button 
             label="Click Me!" 
             onClick={() => alert('Reusable button works!')} 
             variant="primary" 
           />
        </div>
      </div>
    </div>
  );
}

export default App;
