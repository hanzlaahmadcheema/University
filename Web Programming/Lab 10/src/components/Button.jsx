
import PropTypes from 'prop-types';


const Button = ({ label, onClick, variant = 'primary', className = '' }) => {
  return (
    <button 
      className={`premium-btn ${variant} ${className}`} 
      onClick={onClick}
    >
      {label}
    </button>
  );
};

Button.propTypes = {
  label: PropTypes.string.isRequired,
  onClick: PropTypes.func,
  variant: PropTypes.oneOf(['primary', 'secondary', 'danger', 'success']),
  className: PropTypes.string,
};

export default Button;
